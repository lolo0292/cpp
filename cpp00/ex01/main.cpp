#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main() {
    PhoneBook phoneBook;
    std::string cmd;

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, cmd)) {
            std::cout << "\nEOF reçu. Quit.\n";
            break;
        }

        if (cmd == "ADD")
            phoneBook.addContact();
        else if (cmd == "SEARCH")
            phoneBook.searchContact();
        else if (cmd == "EXIT")
            break;
        else if (!cmd.empty())
            std::cout << "Commande inconnue. Utilisez: ADD, SEARCH, EXIT\n";
    }
    return 0;
}
