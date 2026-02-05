/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 03:21:02 by schahir           #+#    #+#             */
/*   Updated: 2025/12/03 03:21:02 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac , char **av) 
{
    Harl harl;
    if(ac != 2)
        return std::cout << "there can only be one argument please choose between 'DEBUG', 'INFO', 'WARNING' and 'ERROR'" << std::endl, 1;
    std::string input = av[1];
    harl.complain_filter(input);
}