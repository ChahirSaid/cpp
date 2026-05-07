/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 09:51:13 by schahir           #+#    #+#             */
/*   Updated: 2026/05/05 10:19:41 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void upper(std::string &str)
{
    for (size_t i = 0; i < str.size(); i++)
        str[i] = std::toupper(str[i]);
}

void printit(int num)
{
    std::cout << num << std::endl;
}

int main()
{
    {    
        std::string arr[3] = {"test", "test", "test"};
        size_t len = 3;
        iter(arr, len, upper);
        for (size_t i = 0; i < len; i++)
            std::cout << arr[i] << std::endl;
    }
    {
        const int arr[5] = {1, 2, 3, 4, 5};
        size_t len = 5;
        iter(arr, len, printit);
    }
}
