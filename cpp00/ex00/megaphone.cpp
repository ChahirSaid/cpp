/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:26:50 by schahir           #+#    #+#             */
/*   Updated: 2025/11/23 23:28:45 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 1;
    }
    std::string args;
    int i = 1;
    while(i <= ac - 1)
    {
        args += av[i];
        i++;
    }
    size_t j = 0;
    while (j < args.size())
    {
        args[j] = std::toupper(args[j]);
        j++;
    }

    std::cout << args << std::endl;
    return 0;
}