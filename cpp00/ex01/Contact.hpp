#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;

    static std::string _promptNonEmpty(const std::string &label);

public:
    Contact();
    bool isEmpty() const;

    // Saisie utilisateur (ADD)
    void setContact();

    // Affichages (SEARCH)
    void displayShort(int index) const; // ligne tableau (index | first | last | nick)
    void displayFull() const;           // tous les champs, un par ligne
};

#endif
