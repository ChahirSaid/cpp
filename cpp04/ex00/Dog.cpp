/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:34:09 by schahir           #+#    #+#             */
/*   Updated: 2025/12/17 18:42:38 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    _type = "Dog";
    std::cout << "[Animal] " << _type << " has been constructed(default)" << std::endl;
}

Dog::Dog(const Dog &other):Animal(other)
{
    std::cout << "[Animal] " << _type << " has been constructed(copy)" << std::endl;
}

Dog& Dog::operator=(const Dog &other)
{
    std::cout << "[Animal] " << _type << " has been asigned" << std::endl;
    if (this != &other)
       Animal::operator=(other);
    return *this;
}

Dog::~Dog()
{
    std::cout << "[Animal] " << _type << " has been destroyed" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof.." << std::endl;
}