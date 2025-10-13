#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
    Contact _contacts[8];
    int     _count;   // nombre de contacts stockés (max 8)
    int     _next;    // prochain index d'insertion (remplacement circulaire)

    static bool _parseIndex(const std::string &s, int &out);

public:
    PhoneBook();

    void addContact();     // commande ADD
    void searchContact() const; // commande SEARCH
};

#endif
