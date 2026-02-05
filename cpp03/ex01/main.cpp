/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 18:35:10 by schahir           #+#    #+#             */
/*   Updated: 2026/02/05 02:25:30 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


int main()
{
	ScavTrap goblu("Goblu");
	goblu.attack("Orc");
	goblu.takeDamage(8);
	goblu.beRepaired(10);
	goblu.guardGate();
}