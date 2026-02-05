/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 01:54:59 by schahir           #+#    #+#             */
/*   Updated: 2025/12/19 17:58:50 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure(): AMateria("cure")
{
	std::cout << "[Materia] of " << _type << " type has been constucted (default)" << std::endl;
}

Cure::Cure(const Cure &other): AMateria(other)
{
	std::cout << "[Materia] of " << _type << " type has been constucted (copy)" << std::endl;	
}

Cure& Cure::operator=(const Cure &other)
{
	std::cout << "[Materia] of " << _type << " type has been assigned" << std::endl;
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

Cure::~Cure()
{
	std::cout << "[Materia] of " << _type << " type has been destroyed" << std::endl;
}

AMateria* Cure::clone() const
{
	return new Cure();
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" <<std::endl;
}