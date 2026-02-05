/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 20:05:26 by schahir           #+#    #+#             */
/*   Updated: 2025/12/15 01:31:52 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("DiamondTrap_clap_name"), ScavTrap(), FragTrap(), _name("DiamondTrap")
{
	this->_hp = FragTrap::_hp;
	this->_ep = 50;
	this->_dmg = FragTrap::_dmg;
	std::cout << "DiamondTrap " << _name << " the ultimate MONSTER appears! (HP: " << _hp << ", EP: " << _ep << ", DMG: " << _dmg << ")" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), _name(name)
{
	this->_hp = FragTrap::_hp;
	this->_ep = 50;
	this->_dmg = FragTrap::_dmg;
	std::cout << "DiamondTrap " << _name << " the ultimate MONSTER appears! (HP: " << _hp << ", EP: " << _ep << ", DMG: " << _dmg << ")" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other): ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name)
{
	std::cout << _name << " has been preserved" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->_name = other._name;
	}
	std::cout << _name << " has been preserved" << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
		if (_hp > 0)
		std::cout << "DiamondTrap " << _name << " has won the battle with " << _hp << " HP and " << _ep << " EP remaining" << std::endl;
	else
		std::cout << "DiamondTrap " << _name << " the ultimate MONSTER has been destroyed" <<std::endl;

}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << _name << std::endl
	<< "ClapTrap name: " << ClapTrap::_name << std::endl;
}