/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 18:54:07 by schahir           #+#    #+#             */
/*   Updated: 2026/02/05 02:23:10 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const ScavTrap &other);
		ScavTrap& operator=(const ScavTrap &other);
		~ScavTrap();
		ScavTrap(std::string name);
		void attack(const std::string& target);
		void guardGate();
};

#endif