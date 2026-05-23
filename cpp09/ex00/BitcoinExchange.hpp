/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 17:31:26 by schahir           #+#    #+#             */
/*   Updated: 2026/05/22 17:34:34 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <algorithm>
#include <exception>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _data;
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);

	public:
		BitcoinExchange();
		~BitcoinExchange();

		void loadData(const std::string& dataFile);
		void processInput(const std::string& inputFile);

		class CouldNotOpenDataFileException;
		class CouldNotOpenInputFileException;
		class BadInputException;
		class NegativeNumberException;
		class LargeNumberException;
		
};

class BitcoinExchange::CouldNotOpenDataFileException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

class BitcoinExchange::CouldNotOpenInputFileException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

class BitcoinExchange::BadInputException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

class BitcoinExchange::NegativeNumberException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

class BitcoinExchange::LargeNumberException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

#endif