/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 17:31:23 by schahir           #+#    #+#             */
/*   Updated: 2026/05/22 17:40:19 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _data(other._data)
{}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		_data = other._data;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadData(const std::string& dataFile)
{
	std::ifstream file(dataFile.c_str());
	if (!file.is_open())
	{
		throw CouldNotOpenDataFileException();
	}

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string date;
		float value;
		if (std::getline(ss, date, ',') && (ss >> value))
		{
			_data[date] = value;
		}
	}
}

void BitcoinExchange::processInput(const std::string& inputFile)
{
	std::ifstream file(inputFile.c_str());
	if (!file.is_open())
	{
		throw CouldNotOpenInputFileException();
	}

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		try
		{
			std::stringstream ss(line);
			std::string date;
			float value;
			char separator;

			if (!(ss >> date >> separator >> value) || separator != '|')
			{
				throw BadInputException();
			}

			if (value < 0)
			{
				throw NegativeNumberException();
			}

			if (value > 1000)
			{
				throw LargeNumberException();
			}

			std::map<std::string, float>::iterator it = _data.lower_bound(date);
			if (it == _data.begin() && date < it->first)
			{
				throw BadInputException();
			}
			if (it == _data.end() || date < it->first)
			{
				--it;
			}
			
			std::cout << date << " => " << value << " = " << value * it->second << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << " => " << line << std::endl;
		}
	}
}

const char* BitcoinExchange::CouldNotOpenDataFileException::what() const throw()
{
	return "could not open data file.";
}

const char* BitcoinExchange::CouldNotOpenInputFileException::what() const throw()
{
	return "could not open input file.";
}

const char* BitcoinExchange::BadInputException::what() const throw()
{
	return "bad input.";
}

const char* BitcoinExchange::NegativeNumberException::what() const throw()
{
	return "not a positive number.";
}

const char* BitcoinExchange::LargeNumberException::what() const throw()
{
	return "too large a number.";
}