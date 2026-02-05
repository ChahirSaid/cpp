/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:12:14 by schahir           #+#    #+#             */
/*   Updated: 2025/12/19 16:55:09 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "[Animal]" << _type << " has been constructed (default)" << std::endl;
}

Animal::Animal(const Animal &other): _type(other._type)
{
    std::cout << "[Animal] " << _type << " has been constructed (copy)" << std::endl;
}

Animal& Animal::operator=(const Animal &other)
{
    std::cout << "[Animal] " << _type << " has been asigned" << std::endl;
    if (this != &other)
        this->_type = other._type;
    return *this;    
}

Animal::~Animal()
{
    std::cout << "[Animal]" << _type << " has been destroyed" << std::endl;
}

std::string Animal::get_type() const
{
    return _type;
}

// void Animal::makeSound() const
// {
//     std::cout << "Unrecognized animal sound" << std::endl;
// }