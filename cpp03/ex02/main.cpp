/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 18:35:10 by schahir           #+#    #+#             */
/*   Updated: 2025/12/14 20:02:09 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"


int main()
{
	FragTrap frag("FR4G-TP");

	frag.attack("CrapTrap");
    frag.takeDamage(40);
    frag.beRepaired(20);

	frag.highFivesGuys();

	FragTrap frag2("EXPLODER");
	frag2.attack("Boss");
	frag2.highFivesGuys();
}
