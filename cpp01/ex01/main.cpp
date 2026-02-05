/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:12:48 by schahir           #+#    #+#             */
/*   Updated: 2025/12/02 15:12:48 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *horde = zombieHorde(7, "Night walker");
	for (int i = 0; i < 7; i++)
	{
		(*(horde + i)).announce();
	}
	delete[] horde;
}