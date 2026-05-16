/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 09:29:22 by schahir           #+#    #+#             */
/*   Updated: 2026/05/16 15:51:01 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>

template <typename T>
typename T::iterator easyfind(T &coi, int i)
{
    typename T::iterator iter = std::find(coi.begin(), coi.end(), i);
    if (iter == coi.end())
        throw std::runtime_error("element not found");
    return iter;
}

#endif