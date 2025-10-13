/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:28:09 by lleichtn          #+#    #+#             */
/*   Updated: 2025/10/13 13:28:12 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int N = 5; //taille de la horde

	Zombie* horde = zombieHorde(N, "Chloe"); // nomme les zombie
	if (!horde)
		return 1;
	for(int i = 0; i < N; ++i)
		horde[i].announce(); // braiiinnnzzz
	delete[] horde; // tue les zombie
	return 0;
}
