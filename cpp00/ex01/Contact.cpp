#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact() : _firstName(), _lastName(), _nickname(), _phoneNumber(), _darkestSecret() {}

bool Contact::isEmpty() const {
    return _firstName.empty() && _lastName.empty() && _nickname.empty()
        && _phoneNumber.empty() && _darkestSecret.empty();
}

std::string Contact::_promptNonEmpty(const std::string &label) {
    std::string s;
    while (true) {
        std::cout << label;
        if (!std::getline(std::cin, s)) {
            // EOF ou erreur d'entrée : on retourne ce qu'on a (peut être vide)
            return "";
        }
        // trim simple (bords)
        size_t start = s.find_first_not_of(" \t\r\n");
        size_t end   = s.find_last_not_of(" \t\r\n");
        if (start == std::string::npos) s.clear();
        else s = s.substr(start, end - start + 1);

        if (!s.empty())
            return s;
        std::cout << "Champ obligatoire, merci de renseigner une valeur.\n";
    }
}

void Contact::setContact() {
    _firstName     = _promptNonEmpty("First name: ");
    if (!std::cin) return;
    _lastName      = _promptNonEmpty("Last name: ");
    if (!std::cin) return;
    _nickname      = _promptNonEmpty("Nickname: ");
    if (!std::cin) return;
    _phoneNumber   = _promptNonEmpty("Phone number: ");
    if (!std::cin) return;
    _darkestSecret = _promptNonEmpty("Darkest secret: ");
    // si cin passe en erreur/EOF au milieu, on peut se retrouver avec des champs vides.
    // La logique ADD dans PhoneBook vérifiera via isEmpty() si nécessaire.
}

static std::string trunc10(const std::string &s) {
    if (s.size() > 10)
        return s.substr(0, 9) + ".";
    return s;
}

void Contact::displayShort(int index) const {
    std::cout << std::setw(10) << index << "|"
              << std::setw(10) << trunc10(_firstName) << "|"
              << std::setw(10) << trunc10(_lastName)  << "|"
              << std::setw(10) << trunc10(_nickname)  << "\n";
}

void Contact::displayFull() const {
    std::cout << "First name:     " << _firstName     << "\n"
              << "Last name:      " << _lastName      << "\n"
              << "Nickname:       " << _nickname      << "\n"
              << "Phone number:   " << _phoneNumber   << "\n"
              << "Darkest secret: " << _darkestSecret << "\n";
}
