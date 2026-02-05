/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 18:50:26 by schahir           #+#    #+#             */
/*   Updated: 2025/12/17 22:34:26 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    _type = "WrongCat";
    std::cout << "[Animal] " << _type << " has been constructed(default)" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other):WrongAnimal(other)
{
    std::cout << "[Animal] " << _type << " has been constructed(copy)" << std::endl;
}
WrongCat& WrongCat::operator=(const WrongCat &other)
{
      std::cout << "[Animal] " << _type << " has been asigned" << std::endl;
    if (this != &other)
       WrongAnimal::operator=(other);
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "[Animal] " << _type << " has been destroyed" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "Meow.." << std::endl;
}
