#include "Replacer.hpp"

#include <fstream>
#include <sstream>  // pour lire tout le fichier en mémoire
#include <iostream> // uniquement si tu veux éventuellement tracer des infos

Replacer::Replacer(const std::string &inputPath, const std::string &s1, const std::string &s2)
: inputPath_(inputPath), outputPath_(), s1_(s1), s2_(s2), lastError_()
{
}

const std::string& Replacer::getOutputPath() const { return outputPath_; }
const std::string& Replacer::getLastError() const { return lastError_; }

void Replacer::setError_(const std::string &msg) { lastError_ = msg; }

void Replacer::buildOutputPath_()
{
    outputPath_ = inputPath_;
    outputPath_ += ".replace";
}

bool Replacer::validateArgs_()
{
    if (inputPath_.empty()) {
        setError_("input filename must not be empty");
        return false;
    }
    if (s1_.empty()) {
        setError_("s1 must not be empty");
        return false;
    }
    buildOutputPath_();
    if (outputPath_.empty()) {
        setError_("failed to build output path");
        return false;
    }
    return true;
}

bool Replacer::readAll_(std::string &outContent)
{
    std::ifstream ifs(inputPath_.c_str(), std::ios::in);

    {
        std::ifstream check(inputPath_.c_str(), std::ios::in);
        if (!check.is_open()) {
            setError_(std::string("cannot open input file: ") + inputPath_);
            return false;
        }
        std::ostringstream oss;
        oss << check.rdbuf(); // conserve le contenu tel quel (y compris \n)
        outContent = oss.str();
    }
    return true;
}

std::string Replacer::replaceAll_(const std::string &src) const
{
    // Cas s1 == s2 : inutile de parcourir (optimisation)
    if (s1_ == s2_) return src;

    std::string result;
    result.reserve(src.size()); // réserve un peu, optimisation simple

    std::string::size_type pos = 0;
    const std::string::size_type n = src.size();
    const std::string::size_type k = s1_.size();

    while (true) {
        std::string::size_type i = src.find(s1_, pos);
        if (i == std::string::npos) {
            // plus d'occurrence : ajouter le suffixe restant
            result.append(src, pos, n - pos);
            break;
        }
        // ajouter la portion avant l'occurrence
        result.append(src, pos, i - pos);
        // ajouter s2
        result.append(s2_);
        // avancer au-delà de l'occurrence trouvée
        pos = i + k;
    }
    return result;
}

bool Replacer::writeAll_(const std::string &content)
{
    std::ofstream ofs(outputPath_.c_str(), std::ios::out | std::ios::trunc);
    if (!ofs.is_open()) {
        setError_(std::string("cannot open output file: ") + outputPath_);
        return false;
    }
    ofs << content;
    if (!ofs.good()) {
        setError_(std::string("write failed: ") + outputPath_);
        return false;
    }
    return true;
}

bool Replacer::process()
{
    if (!validateArgs_())
        return false;

    std::string inputContent;
    if (!readAll_(inputContent))
        return false;

    const std::string outputContent = replaceAll_(inputContent);

    if (!writeAll_(outputContent))
        return false;

    return true;
}
