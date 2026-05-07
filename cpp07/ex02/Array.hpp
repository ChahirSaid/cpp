/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 10:25:31 by schahir           #+#    #+#             */
/*   Updated: 2026/05/06 16:22:38 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
    private:
        T* arr;
        unsigned int len;
    public:
        Array(): arr(NULL), len(0) {};
        Array(unsigned int n): arr(new T[n]()), len(n) {};
        Array(const Array& other):arr(NULL), len(other.len)
        {
            if (len)
            {
                arr = new T[len];
                for (unsigned int i = 0; i < len; i++)
                    arr[i] = other.arr[i];
            }
        };
        Array& operator=(const Array& other)
        {
            if (this != &other)
            {
                delete[] arr;
                len = other.len;
                if (len)
                {
                    arr = new T[len];
                    for (unsigned int i = 0; i < len; i++)
                        arr[i] = other.arr[i]
                }
                else
                    arr = NULL;
            }
            return *this;
        }
        ~Array() {delete[] arr;};
};

#endif