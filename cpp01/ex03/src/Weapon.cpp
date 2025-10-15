#include "Weapon.hpp"

Weapon::Weapon(const std::string &type) : _type(type) {} //constructeur

Weapon::~Weapon() {} //destructeur

const std::string &Weapon::getType() const
{ return _type; } //retourne le type

void Weapon::setType(const std::string &type) //affecte valeur a type
{ _type = type; }