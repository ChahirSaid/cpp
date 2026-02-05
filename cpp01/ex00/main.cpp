/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:38:09 by schahir           #+#    #+#             */
/*   Updated: 2025/12/02 14:38:09 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie z1("Zombie 1");
	z1.announce();
	Zombie *z2 = newZombie("Zombie 2");
	z2->announce();
	randomChump("Zombie 3");
	delete z2;
}