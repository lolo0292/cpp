#include "HumanA.hpp"
#include "HumanB.hpp"

int main() {
    {
        Weapon club = Weapon("gun");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("sword");
        bob.attack();
    }
    {
        Weapon club = Weapon("Flamethrower");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("Crossbow");
        jim.attack();
    }
    return 0;
}
