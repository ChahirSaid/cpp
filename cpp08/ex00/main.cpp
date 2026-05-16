/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 09:30:17 by schahir           #+#    #+#             */
/*   Updated: 2026/05/16 15:55:22 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
   {
        std::vector<int> vec;
        for (int i = 0; i < 10; i++)
        {
            vec.push_back(i);
        }
        for (int i = 0; i < 10; i++)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
        try
        {
            easyfind(vec, 2);
            easyfind(vec, 99);
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    {
        std::list<int> lst;
        for (int i = 0; i < 10; i++)
        {
            lst.push_back(i);
        }
        for (int i = 0; i < 10; i++)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
        try
        {
            easyfind(lst, 5);
            easyfind(lst, 99);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    {
        std::deque<int> dq;
        for (int i = 5; i < 10; i++)
        {
            dq.push_back(i);
        }
        for (int i = 0; i < 5; i++)
        {
            
            dq.push_front(i);
        }
        for (int i = 0; i < 10; i++)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
        try
        {
            easyfind(dq, 2);
            easyfind(dq, 99); 
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}