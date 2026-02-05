/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:57:06 by schahir           #+#    #+#             */
/*   Updated: 2026/02/05 02:02:04 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact add(int *flag)
{
    std::string buffer;
    Contact fill;
    firstname:
    std::cout <<"first name -> " << std::endl;
    if (!std::getline(std::cin, buffer))
       return (*flag = 1, fill);
    if (buffer.empty())
        goto firstname;
    fill.set_fname(buffer);
    lastname:
    std::cout <<"last name -> " << std::endl;
    if (!std::getline(std::cin, buffer))
       return (*flag = 1, fill);
    if (buffer.empty())
        goto lastname;
    fill.set_lname(buffer);
    nickname:
    std::cout <<"nickname -> " << std::endl;
    if (!std::getline(std::cin, buffer))
       return (*flag = 1, fill);
    if (buffer.empty())
        goto nickname;
    fill.set_nickname(buffer);
    number:
    std::cout <<"number -> " << std::endl;
    if (!std::getline(std::cin, buffer))
       return (*flag = 1, fill);
    if (buffer.empty())
        goto number;
    for(size_t i = 0; i < buffer.size(); i++)
    {
        if (!std::isdigit(buffer[i]))
            goto number;
    }
    fill.set_number(buffer);
    secret:
    std::cout <<"darkest secret -> " << std::endl;
    if (!std::getline(std::cin, buffer))
       return (*flag = 1, fill);
    if (buffer.empty())
        goto secret;
    fill.set_secret(buffer);
    return fill;
}


int main()
{
    Contact c;
    std::string buffer;
    PhoneBook pb;
    int flag = 0;
    while(1)
    {
        std::cout << "Select between 'ADD', 'SEARCH' and 'EXIT'" << std::endl;
        if (!std::getline(std::cin, buffer))
            {
                flag = 1;
                break;
            }
        if(buffer == "ADD")
        {
            c = add(&flag);
            if (flag)
                break;
            pb.add_contact(c);
            std::cout << "contact added successfully" << std::endl;
        }
        else if(buffer == "SEARCH")
        {
            pb.display();
            std::cout << "Enter an id to view full details" << std::endl;
            if(!std::getline(std::cin, buffer))
            {
                flag = 1;
                break;
            }
            pb.full_display(buffer);
        }
        else if(buffer == "EXIT")
        {
            std::cout << "Exiting Phonebook.." << std::endl;
            break;
        }
        else
            continue;
    }
    if (flag)
        return 1;
    return 0;
}