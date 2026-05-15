/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 09:30:17 by schahir           #+#    #+#             */
/*   Updated: 2026/05/15 21:04:45 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
   std::vector<int> vec;
   for (int i = 0; i < 10; i++){
    vec.push_back(i);
   }
    try
    {
        easyfind(vec, 2);
        easyfind(vec, 99);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}