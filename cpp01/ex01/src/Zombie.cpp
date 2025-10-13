/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:28:15 by lleichtn          #+#    #+#             */
/*   Updated: 2025/10/13 13:28:16 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : name("") {} //cree les zombie avec nom vide

Zombie::~Zombie() //tue les zombie
{
	std::cout << this->name << " destroyed" << std::endl;
}

void Zombie::announce(void)  // dis leur phrase
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string& n) 
{
	this->name = n;
}
