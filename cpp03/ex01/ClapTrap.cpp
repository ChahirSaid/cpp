/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 17:49:40 by schahir           #+#    #+#             */
/*   Updated: 2025/12/15 15:43:46 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("Claptrap"), _hp(10), _ep(10), _dmg(10)
{
	std::cout << "A wild " << _name << " appears! (HP: " << _hp << ", EP: " << _ep <<  ", DMG: " << _dmg << ")" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10), _dmg(10)
{
	std::cout << "A wild " << _name << " appears! (HP: " << _hp << ", EP: " << _ep <<  ", DMG: " << _dmg << ")" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other): _name(other._name), _hp(other._hp), _ep(other._ep), _dmg(other._dmg)
{
	std::cout << _name << " has been preserved" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << _name << " has been preserved" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hp = other._hp;
		this->_ep = other._ep;
		this->_dmg = other._dmg;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	if (_hp > 0)
		std::cout << "ClapTrap " << _name << " has retreated surviving with " << _hp << " HP and " << _ep << " EP remaining" << std::endl;
	else
		std::cout << "ClapTrap " << _name << " met his end failing to overcome the challenge" <<std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (_hp <= 0)
	{
		std::cout << "ClapTrap " << _name << " already dead!"<< std::endl;
		return ;
	}
	if (_ep == 0)
	{
		std::cout << "ClapTrap " << _name <<  " Energy points depleted" << std::endl;
		return ;
	}
	_ep--;
	std::cout << "ClapTrap " << _name << " attacks " << target << " dealing " << _dmg << " points of damage! Energy points left : " << _ep << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	_hp -=amount;
	if (_hp <= 0)
		std::cout << "ClapTrap " << _name << " died" << std::endl;
	else
		std::cout << "ClapTrap " << _name << " receives a staggering " << amount << " of damage leaving him with " << _hp << "HP" << std::endl;	
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hp <= 0)
    {
        std::cout << "ClapTrap " << _name << " has already died and can no longer be repaired" << std::endl;
        return;
    }
    if (_ep == 0)
    {
        std::cout << "ClapTrap " << _name << " Energy points depleted" << std::endl;
        return;
    }
	_ep--;
	_hp += amount;
	std::cout << "ClapTrap " << _name << " casts healing, recovering " << amount << "HP" << std::endl;
}