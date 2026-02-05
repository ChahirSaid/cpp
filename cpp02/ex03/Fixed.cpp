/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 21:11:56 by schahir           #+#    #+#             */
/*   Updated: 2026/02/05 02:20:19 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed():_value(0)
{}

Fixed::Fixed(const int val):_value(val << _bits)
{}

Fixed::Fixed(const float fp):_value(roundf(fp * (1 << _bits)))
{}

Fixed::Fixed(const Fixed &other)
{
    *this = other;
}

Fixed& Fixed::operator=(const Fixed &other)
{
    this->_value = other._value;
    return *this;
}

int Fixed::getRawBits() const
{
    return _value;
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

float Fixed::toFloat() const
{
    return ((float)_value / (1 << _bits));
}

int Fixed::toInt() const
{
    return (int)toFloat();
}

Fixed::~Fixed()
{}

bool Fixed::operator>(const Fixed &other) const
{
    return (this->_value > other._value);
}

bool Fixed::operator<(const Fixed &other) const
{
    return (this->_value < other._value);
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (this->_value >= other._value);
}

bool Fixed::operator<=(const Fixed &other) const
{
    return (this->_value <= other._value);
}

bool Fixed::operator==(const Fixed &other) const
{
    return (this->_value == other._value);
}

bool Fixed::operator!=(const Fixed &other) const
{
    return (this->_value != other._value);
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(this->_value + other._value);
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;
    result.setRawBits((this->_value * other._value) >> _bits);
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(this->_value - other._value);
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed result;
    result.setRawBits((this->_value << _bits) / other._value);
    return result;
}

Fixed& Fixed::operator++()
{
    _value++; 
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;
    _value++;
    return tmp;
}

Fixed& Fixed::operator--()
{
    _value--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
    _value--;
    return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return a;
    return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return a;
    return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a < b)
        return b;
    return a;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return b;
    return a;
}

std::ostream& operator<<(std::ostream &out, const Fixed &other)
{
    out << other.toFloat();
    return out;
}