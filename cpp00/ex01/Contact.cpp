/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:51:36 by schahir           #+#    #+#             */
/*   Updated: 2025/11/21 17:55:22 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){}

void Contact::set_fname(std::string fname)
{
    _fname = fname;
}
void Contact::set_lname(std::string lname)
{
    _lname = lname;
}
void Contact::set_nickname(std::string nickname)
{
    _nickname = nickname;
}
void Contact::set_number(std::string number)
{
    _number = number;
}
void Contact::set_secret(std::string secret)
{
    _secret = secret;
}

std::string Contact::get_fname() const
{
    return _fname;
}
std::string Contact::get_lname() const
{
    return _lname;
}
std::string Contact::get_nickname() const
{
    return _nickname;
}
std::string Contact::get_number() const
{
    return _number;
}
std::string Contact::get_secret() const
{
    return _secret;
}

bool Contact::validate_form() const
{
    return (_fname.empty() || _lname.empty() || _nickname.empty() || _number.empty() || _secret.empty());
}

bool Contact::validate_number() const
{
    for(size_t i= 0;i<_number.size();i++)
    {
        if (!std::isdigit(_number[i]))
            return false;
    }
    return true;
}