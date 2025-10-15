/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:27:46 by lleichtn          #+#    #+#             */
/*   Updated: 2025/10/13 14:39:07 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;
	std::cout << "The memory address of the string variable: "<< &string << std::endl;
	std::cout << "The memory address held by stringPTR:"<< stringPTR << std::endl;
	std::cout << "The memory address held by stringREF:"<< &stringREF << std::endl;
	std::cout << std::endl; //linge vide entre les deux blocs
	std::cout << "Valeur de la string : " << string << std::endl;
	std::cout << "Valeur pointée par stringPTR : " << *stringPTR << std::endl;
	std::cout << "Valeur référencée par stringREF : " << stringREF << std::endl;

	return 0;	
}