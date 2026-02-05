/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 20:27:08 by schahir           #+#    #+#             */
/*   Updated: 2025/12/02 20:27:08 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug()
{
	std::cout << "[ DEBUG ]" << std::endl <<"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger. I really do!" << std::endl;
}
void Harl::info()
{
	std::cout << "[ INFO ]" << std::endl << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void Harl::warning()
{
	std::cout << "[ WARNING ]" << std::endl << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}
void Harl::error()
{
	std::cout << "[ ERROR ]" << std::endl << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	void (Harl::*complaints[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

std::string complaints_lvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

for (int i = 0; i < 4; i++)
{
	if(complaints_lvl[i] == level)
	{
		(this->*complaints[i])();
		break;
	}
}
}

void Harl::complain_filter(std::string level)
{
	void (Harl::*complaints[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string complaints_lvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int complaints_index = -1;

	for (int i = 0; i < 4; i++)
	{
		if (complaints_lvl[i] == level)
		{
			complaints_index = i;
			break;
		}
	}

	switch (complaints_index)
	{
		case 0:
			for(int i = 0; i < 4; i++){(this->*complaints[i])();}
			break;
		case 1:
			for(int i = 1; i < 4; i++){(this->*complaints[i])();}
			break;
		case 2:
			for(int i = 2; i < 4; i++){(this->*complaints[i])();}
			break;
		case 3:
			(this->*complaints[3])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}