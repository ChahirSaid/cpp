/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 19:35:59 by schahir           #+#    #+#             */
/*   Updated: 2025/12/15 15:45:21 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	_name = "FragTrap";
	_hp = 100;
	_ep = 100;
	_dmg = 30;
	std::cout << "FragTrap " << _name << " the ultimate offensive ClapTrap appears! (HP: " << _hp << ", EP: " << _ep << ", DMG: " << _dmg << ")" << std::endl;
}

FragTrap::FragTrap(std::string name):ClapTrap(name)
{
	_hp = 100;
	_ep = 100;
	_dmg = 30;
	std::cout << "FragTrap " << _name << " the ultimate offensive ClapTrap appears! (HP: " << _hp << ", EP: " << _ep << ", DMG: " << _dmg << ")" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other):ClapTrap(other)
{
	std::cout << _name << " has been preserved" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
	std::cout << _name << " has been preserved" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

FragTrap::~FragTrap()
{
	if (_hp > 0)
		std::cout << "FragTrap " << _name << " has won the battle with " << _hp << " HP and " << _ep << " EP remaining" << std::endl;
	else
		std::cout << "FragTrap " << _name << " has been destroyed causing a massive explosion " <<std::endl;

}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << _name << " requests a High Five" << std::endl;
}
