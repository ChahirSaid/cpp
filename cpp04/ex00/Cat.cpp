/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:34:03 by schahir           #+#    #+#             */
/*   Updated: 2025/12/17 18:42:46 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    _type = "Cat";
    std::cout << "[Animal] " << _type << " has been constructed(default)" << std::endl;
}

Cat::Cat(const Cat &other):Animal(other)
{
    std::cout << "[Animal] " << _type << " has been constructed(copy)" << std::endl;
}
Cat& Cat::operator=(const Cat &other)
{
      std::cout << "[Animal] " << _type << " has been asigned" << std::endl;
    if (this != &other)
       Animal::operator=(other);
    return *this;
}

Cat::~Cat()
{
    std::cout << "[Animal] " << _type << " has been destroyed" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow.." << std::endl;
}