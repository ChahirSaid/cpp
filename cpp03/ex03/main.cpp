/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 18:35:10 by schahir           #+#    #+#             */
/*   Updated: 2026/02/05 02:26:23 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"

#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "===== BASIC CONSTRUCTION =====" << std::endl;
	DiamondTrap d1("Said");

	std::cout << "\n===== WHO AM I =====" << std::endl;
	d1.whoAmI();

	std::cout << "\n===== ATTACK TEST =====" << std::endl;
	d1.attack("a poor evaluator");

	std::cout << "\n===== COPY TEST =====" << std::endl;
	DiamondTrap d2(d1);
	d2.whoAmI();

	std::cout << "\n===== ASSIGNMENT TEST =====" << std::endl;
	DiamondTrap d3;
	d3 = d1;
	d3.whoAmI();

	std::cout << "\n===== END OF PROGRAM =====" << std::endl;
	return 0;
}
