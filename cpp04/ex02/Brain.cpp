/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 22:44:36 by schahir           #+#    #+#             */
/*   Updated: 2025/12/21 17:13:10 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "[Brain] has been constructed (default)" << std::endl;
}

Brain::Brain(const Brain &other):_ideas(other._ideas)
{
    std::cout << "[Brain] has been constructed (copy)" << std::endl;
}
Brain& Brain::operator=(const Brain &other)
{
    std::cout << "[Brain] has been asigned" << std::endl;
    if (this != &other)
    {   
        for (int i = 0; i < 100; i++)
            _ideas[i] = other._ideas[i];
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "[Brain] has been destroyed" << std::endl;
}