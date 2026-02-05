/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 01:34:30 by schahir           #+#    #+#             */
/*   Updated: 2025/12/21 14:08:26 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(): _type("Unknown")
{
	std::cout << "[Materia] of " << _type << " type has been constucted (default)" << std::endl;
}

AMateria::AMateria(const AMateria &other):_type(other._type)
{
	std::cout << "[Materia] of " << _type << " type has been constucted (copy)" << std::endl;
}

AMateria& AMateria::operator=(const AMateria &other)
{
	std::cout << "[Materia] of " << _type << " type has been asigned" << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

AMateria::~AMateria()
{
	std::cout << "[Materia] of " << _type << " type has been destroyed" << std::endl;
}

AMateria::AMateria(std::string const & type): _type(type)
{
	std::cout << "[Materia] of " << _type << " type has been constucted (parametrized)" << std::endl;
}

std::string const& AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}