#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>

PhoneBook::PhoneBook() : _count(0), _next(0) {}

bool PhoneBook::_parseIndex(const std::string &s, int &out) 
{
    if (s.empty())
        return false;
    // vérifier que s est strictement composé de chiffres
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }
    // conversion simple (valeurs raisonnables ici)
    int val = 0;
    for (size_t i = 0; i < s.size(); ++i)
        val = val * 10 + (s[i] - '0');
    out = val;
    return true;
}

void PhoneBook::addContact() {
    Contact c;
    std::cout << "=== ADD A CONTACT ===\n";
    c.setContact();
    if (!std::cin) { // EOF pendant la saisie
        std::cout << "\nEntrée interrompue (EOF). Retour au menu.\n";
        return;
    }
    // Tous les champs sont obligatoires : on refuse si un champ est vide.
    if (c.isEmpty()) {
        std::cout << "Contact invalide (champs vides). Annulé.\n";
        return;
    }
    _contacts[_next] = c;
    _next = (_next + 1) % 8;
    if (_count < 8) _count++;
    std::cout << "Contact ajouté (" << _count << "/8).\n";
}

void PhoneBook::searchContact() const {
    if (_count == 0) {
        std::cout << "PhoneBook is empty.\n";
        return;
    }

    std::cout << std::setw(10) << "index" << "|"
              << std::setw(10) << "first name" << "|"
              << std::setw(10) << "last name"  << "|"
              << std::setw(10) << "nickname"   << "\n";

    for (int i = 0; i < _count; ++i)
        _contacts[i].displayShort(i);

    std::cout << "Enter index to display: ";
    std::string s;
    if (!std::getline(std::cin, s)) {
        std::cout << "\nEntrée interrompue (EOF). Retour au menu.\n";
        return;
    }
    int idx = -1;
    if (!_parseIndex(s, idx) || idx < 0 || idx >= _count || _contacts[idx].isEmpty()) {
        std::cout << "Index invalide.\n";
        return;
    }
    std::cout << "=== CONTACT #" << idx << " ===\n";
    _contacts[idx].displayFull();
}
