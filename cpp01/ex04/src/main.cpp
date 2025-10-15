#include <iostream>
#include "Replacer.hpp"

int main(int argc, char **argv)
{
    if (argc != 4) {
        std::cerr << "Usage: " << (argc > 0 ? argv[0] : "sed_is_for_losers")
                  << " <filename> <s1> <s2>\n";
        return 1;
    }

    const std::string filename = argv[1];
    const std::string s1 = argv[2];
    const std::string s2 = argv[3];

    Replacer r(filename, s1, s2);
    if (!r.process()) {
        std::cerr << "Error: " << r.getLastError() << "\n";
        return 1;
    }

    // Affichage facultatif (tu peux supprimer si tu veux un binaire silencieux)
    std::cout << "Created: " << r.getOutputPath() << "\n";
    return 0;
}
