/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:35:09 by schahir           #+#    #+#             */
/*   Updated: 2025/11/23 16:22:30 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp" 

class PhoneBook
{
    private:
        Contact contacts[8];
        int cur_contact;
        bool is_full;
    public:
        PhoneBook();
        void add_contact(Contact info);
        void display() const;
        void full_display(std::string index) const;
        std::string truncate(std::string _new) const;
};

#endif
