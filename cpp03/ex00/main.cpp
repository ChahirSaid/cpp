/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 18:35:10 by schahir           #+#    #+#             */
/*   Updated: 2025/12/14 18:53:08 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap nemo("nemo");
	nemo.attack("Orc");
	nemo.takeDamage(8);
	nemo.beRepaired(10);
}