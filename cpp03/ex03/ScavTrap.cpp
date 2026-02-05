/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 18:54:04 by schahir           #+#    #+#             */
/*   Updated: 2026/02/05 02:22:55 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	_name = "ScavTrap";
	_hp = 100;
	_ep = 50;
	_dmg = 20;
	std::cout << "ScavTrap " << _name << " the ultimate defensive ClapTrap appears! (HP: " << _hp << ", EP: " << _ep << ", DMG: " << _dmg << ")" << std::endl;

}

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other)
{
	std::cout << _name << " has been preserved" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << _name << " has been preserved" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

ScavTrap::~ScavTrap()
{
	if (_hp > 0)
		std::cout << "ScavTrap " << _name << " has retreated surviving with " << _hp << " HP and " << _ep << " EP remaining" << std::endl;
	else
		std::cout << "ScavTrap " << _name << " met his end failing to overcome the challenge" <<std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	_hp = 100;
	_ep = 50;
	_dmg = 20;
	std::cout << "ScavTrap " << _name << " the ultimate defensive ClapTrap appears! (HP: " << _hp << ", EP: " << _ep << ", DMG: " << _dmg << ")" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (_hp <= 0)
	{
		std::cout << "ScavTrap " << _name << " already dead!"<< std::endl;
		return ;
	}
	if (_ep == 0)
	{
		std::cout << "ScavTrap " << _name <<  " Energy points depleted" << std::endl;
		return ;
	}
	_ep--;
	std::cout << "ScavTrap " << _name << " attacks " << target << " dealing " << _dmg << " points of damage! Energy points left : " << _ep << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " casted  his ultimate move, switching to 'Gate keeper Mode' enemies will have a hard time breaching" << std::endl;
}