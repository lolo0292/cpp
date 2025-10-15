#ifndef REPLACER_HPP
#define REPLACER_HPP

#include <string>

class Replacer {
public:
    Replacer(const std::string &inputPath, const std::string &s1, const std::string &s2);

    bool                process();
    const std::string&  getOutputPath() const;
    const std::string&  getLastError() const;

private:
    bool                validateArgs_();
    void                buildOutputPath_();
    bool                readAll_(std::string &outContent);
    std::string         replaceAll_(const std::string &src) const;
    bool                writeAll_(const std::string &content);
    void                setError_(const std::string &msg);

    std::string inputPath_;
    std::string outputPath_;
    std::string s1_;
    std::string s2_;
    std::string lastError_;
};

#endif // REPLACER_HPP
