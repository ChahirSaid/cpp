/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 09:51:25 by schahir           #+#    #+#             */
/*   Updated: 2026/05/05 09:51:26 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T, typename U>
void iter(T* arr, size_t len, U fun)
{
    for (size_t i =0; i < len; i++)
        fun(arr[i]);
}

template <typename T, typename U>
void iter(const T* arr, size_t len, U fun)
{
    for (size_t i = 0; i < len; i++)
        fun(arr[i]);
}

#endif