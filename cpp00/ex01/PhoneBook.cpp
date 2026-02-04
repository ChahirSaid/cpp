/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 20:41:37 by schahir           #+#    #+#             */
/*   Updated: 2025/11/23 15:37:21 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook():cur_contact(0),is_full(0)
{}

void PhoneBook::add_contact(Contact info)
{
    contacts[cur_contact] = info;
    cur_contact++;
    if (cur_contact == 8)
    {
        is_full = 1;
        cur_contact = 0;
    }
}

std::string PhoneBook::truncate(std::string _new) const
{
    if(_new.size() > 10)
        return(_new.substr(0,9) + ".");
    return _new;
}

void PhoneBook::display() const
{
    int to_display = 0;
    if(is_full)
        to_display = 8;
    else
        to_display = cur_contact;
    for(int i = 0; i< to_display;i++)
    {
        std::cout << std::setw(10) << i<<"|"<<
        std::setw(10) <<truncate(contacts[i].get_fname()) << "|"<<
        std::setw(10) <<truncate(contacts[i].get_lname()) << "|"<<
        std::setw(10) <<truncate(contacts[i].get_nickname()) << "|" << std::endl;
    }
}

void PhoneBook::full_display(std::string index) const
{
    std::string buffer;
    int i = -1;
    if(index == "0")
        i = 0;
    else if (index == "1")
        i = 1;
    else if (index == "2")
        i = 2;
    else if (index == "3")
        i = 3;
    else if (index == "4")
        i = 4;
    else if (index == "5")
        i = 5;
    else if (index == "6")
        i = 6;
    else if (index == "7")
        i = 7;
    if (i == -1)
    {
        std::cout << "Invalid entry!" << std::endl;
    }
    else
        {
            if(contacts[i].get_fname().empty())
            {
                std::cout << "Invalid entry!" << std::endl;
                return ;
            }
            std::cout << contacts[i].get_fname() << std::endl;
            std::cout << contacts[i].get_lname() << std::endl;
            std::cout << contacts[i].get_nickname() << std::endl;
            std::cout << contacts[i].get_number() << std::endl;
            std::cout << contacts[i].get_secret() << std::endl;
        }
}