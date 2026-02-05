/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 18:50:24 by schahir           #+#    #+#             */
/*   Updated: 2025/12/17 22:28:31 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "[Wrong animal]" << _type << " has been constructed (default)" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other): _type(other._type)
{
    std::cout << "[Wrong animal]" << _type << " has been constructed (copy)" << std::endl;

}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
    std::cout << "[Wrong animal] " << _type << " has been asigned" << std::endl;
    if (this != &other)
        _type = other._type;
    return *this;
}
WrongAnimal::~WrongAnimal()
{
    std::cout << "[Wrong animal]" << _type << " has been destroyed" << std::endl;
}

void WrongAnimal::MakeSound() const
{
    std::cout << "Unrecognized Wrong Animal sound" << std::endl;
}