/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 02:07:27 by schahir           #+#    #+#             */
/*   Updated: 2025/12/21 16:10:07 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    
    ICharacter *player = new Character("player");
    ICharacter *enemy = new Character("enemy");
    AMateria *tmp;
    tmp = src->createMateria("ice");
    player->equip(tmp);
    AMateria *to_free = tmp;
    player->use(0,*enemy);
    player->unequip(0);
    src->learnMateria(new Cure());
    tmp = src->createMateria("cure");
    AMateria *new_free = tmp;
    player->equip(tmp);
    player->use(0,*enemy);
    player->unequip(0);
    
    delete new_free;
    delete to_free;
    delete enemy;
    delete player;
    delete src;
}