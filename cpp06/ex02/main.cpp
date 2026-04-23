/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 07:00:00 by schahir           #+#    #+#             */
/*   Updated: 2026/04/23 14:45:39 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

int main(void)
{
	std::srand(std::time(0));

	for (int i = 0; i < 5; i++)
	{
		Base* obj = generate();

		std::cout << "Object " << i + 1 << " identified by pointer: ";
		identify(obj);

		std::cout << "Object " << i + 1 << " identified by reference: ";
		identify(*obj);

		delete obj;
		std::cout << std::endl;
	}

	return 0;
}
