/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 22:44:39 by schahir           #+#    #+#             */
/*   Updated: 2025/12/17 22:51:34 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
    private:
        std::string _ideas[100];
    public:
        Brain();
        Brain(const Brain &other);
        Brain& operator=(const Brain &other);
        ~Brain();  
};

#endif