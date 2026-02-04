/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:57:06 by schahir           #+#    #+#             */
/*   Updated: 2025/11/23 15:47:10 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact add(int *flag)
{
    std::string buffer;
    Contact fill;
    std::cout <<"first name -> " << std::endl;
    if (!std::getline(std::cin, buffer))
       return (*flag = 1, fill);
    fill.set_fname(buffer);
    std::cout <<"last name -> " << std::endl;
    if (!std::getline(std::cin, buffer))
       return (*flag = 1, fill);
    fill.set_lname(buffer);
    std::cout <<"nickname -> " << std::endl;
    if (!std::getline(std::cin, buffer))
       return (*flag = 1, fill);
    fill.set_nickname(buffer);
    std::cout <<"number -> " << std::endl;
    if (!std::getline(std::cin, buffer))
       return (*flag = 1, fill);
    fill.set_number(buffer);
    std::cout <<"darkest secret -> " << std::endl;
    if (!std::getline(std::cin, buffer))
       return (*flag = 1, fill);
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
            if (c.validate_form())
            {
                std::cout << "Error: field must contain at least one character" << std::endl;
                continue;
            }
            if (!c.validate_number())
            {
                std::cout << "Error: Phone number must only contain digits" << std::endl;
                continue;
            }
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