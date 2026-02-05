/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 16:05:43 by schahir           #+#    #+#             */
/*   Updated: 2025/12/20 16:48:36 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(): _name("Unnamed")
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << "[Character] " << _name << " has been constucted (default)" << std::endl;
}

Character::Character(const Character &other): _name(other._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	std::cout << "[Character] " << _name << " has been constucted (copy)" << std::endl;
}

Character& Character::operator=(const Character &other)
{
	std::cout << "[Character] " << _name << " has been assigned" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i])
				delete _inventory[i];
		}
		for (int i = 0; i < 4; i++)
		{
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else _inventory[i] = NULL;
		}
		_name = other._name;
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
	std::cout << "[Character] " << _name << " has been destroyed" << std::endl;
}

Character::Character(const std::string &name): _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << "[Character] " << _name << " has been constucted (parametrized)" << std::endl;
}

std::string const& Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3 || _inventory[idx] == NULL)
		return ;
	_inventory[idx]->use(target);
}