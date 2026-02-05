/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:43:31 by schahir           #+#    #+#             */
/*   Updated: 2026/02/05 01:58:12 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>

class  Contact
{
    private:
        std::string _fname;
        std::string _lname;
        std::string _nickname;
        std::string _number;
        std::string _secret;
    public:
        Contact();
        
        void set_fname(std::string fname);
        void set_lname(std::string lname);
        void set_nickname(std::string nickname);
        void set_number(std::string number);
        void set_secret(std::string secret);

        std::string get_fname() const;
        std::string get_lname() const;
        std::string get_nickname() const;
        std::string get_number() const;
        std::string get_secret() const;

};

#endif