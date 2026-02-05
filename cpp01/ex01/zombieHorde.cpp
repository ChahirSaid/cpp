/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:02:00 by schahir           #+#    #+#             */
/*   Updated: 2025/12/02 15:02:00 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *z = new Zombie[N];
	int i = 0;

	while (i < N)
	{
	(*(z + i)).set_name(name);
		i++;
	}
	return z;
}