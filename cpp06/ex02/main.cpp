/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 07:00:00 by schahir           #+#    #+#             */
/*   Updated: 2026/04/29 01:00:16 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

int main(void)
{
	std::srand(std::time(0));

	for (int i = 0; i < 5; i++)
	{
		Base* obj = generate();

		std::cout << "Object " << i + 1 << "pointer: ";
		identify(obj);
		try
		{
			std::cout << "Object " << i + 1 << "reference: ";
			identify(*obj);
		}
		catch(std::bad_cast &e)
		{
			std::cout << "error: " << e.what() << std::endl;
		}
		delete obj;
		std::cout << std::endl;
	}
}
