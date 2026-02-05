/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:06:17 by schahir           #+#    #+#             */
/*   Updated: 2025/12/02 18:06:17 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main() {
    {
        Weapon club = Weapon("crude spiked clubbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb");
        HumanA bob("Bob", club);
        bob.attack();
        club.set_type("some other type of clubbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb");
        bob.attack();
    }
    std::cout << std::endl;
    {
        Weapon club = Weapon("crude spiked clubbbbbbbbbbbbbbbbbbbbbbbbbb");
        HumanB jim("Jim");
        jim.attack();
        jim.set_weapon(club);
        jim.attack();
        club.set_type("some other type of clubbbbbbbbbbbbbbbbbbbbbbbbbbbbbb");
        jim.attack();
    }
    return 0;
}