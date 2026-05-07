/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 10:25:31 by schahir           #+#    #+#             */
/*   Updated: 2026/05/07 14:46:27 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <cstdlib>

template <typename T>
class Array
{
    private:
        T* _arr;
        unsigned int _size;
    public:
        Array(): _arr(NULL), _size(0) {};
        Array(unsigned int n): _arr(new T[n]()), _size(n) {};
        Array(const Array& other):_arr(NULL), _size(other._size)
        {
            if (_size)
            {
                _arr = new T[_size];
                for (unsigned int i = 0; i < _size; i++)
                    _arr[i] = other._arr[i];
            }
        };
        Array& operator=(const Array& other)
        {
            if (this != &other)
            {
                delete[] _arr;
                _size = other._size;
                if (_size)
                {
                    _arr = new T[_size];
                    for (unsigned int i = 0; i < _size; i++)
                        _arr[i] = other._arr[i];
                }
                else
                    _arr = NULL;
            }
            return *this;
        }
        ~Array() {delete[] _arr;};
        T& operator[](unsigned int i)
        {
            if (i >= _size)
                throw std::out_of_range("Index out of bounds!");
            return _arr[i];
        }
        const T& operator[](unsigned int i) const
        {
            if (i >= _size)
                throw std::out_of_range("Index out of bounds!");
            return _arr[i];
        }
        unsigned int size() const
        {
            return _size;
        }
};

#endif