/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 01:55:04 by schahir           #+#    #+#             */
/*   Updated: 2025/12/19 17:58:56 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"


Ice::Ice(): AMateria("ice")
{
	std::cout << "[Materia] of " << _type << " type has been constucted (default)" << std::endl;
}

Ice::Ice(const Ice &other): AMateria(other)
{
	std::cout << "[Materia] of " << _type << " type has been constucted (copy)" << std::endl;
}

Ice& Ice::operator=(const Ice &other)
{
	std::cout << "[Materia] of " << _type << " type has been assigned" << std::endl;
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

Ice::~Ice()
{
	std::cout << "[Materia] of " << _type << " type has been destroyed" << std::endl;
}

AMateria* Ice::clone() const
{
	return new Ice();
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" <<std::endl;
}