/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:48:04 by schahir           #+#    #+#             */
/*   Updated: 2025/12/19 01:32:50 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    int size = 4;
    const Animal *animals[size];

    for (int i = 0; i < size / 2; i++)
        animals[i] = new Dog();
    for (int i = size / 2; i < size; i++)
        animals[i] = new Cat();
    for (int i = 0; i < size; i++)
        delete animals[i];
    std::cout << "=============Testing shallow/deep==============" << std::endl;
    Cat a;
    Cat b(a);
    a = b;
    std::cout << "=============Testing done==============" << std::endl;
}
