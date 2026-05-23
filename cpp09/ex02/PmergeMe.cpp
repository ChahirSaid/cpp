/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 17:31:45 by schahir           #+#    #+#             */
/*   Updated: 2026/05/22 17:41:56 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"



PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : _vec(other._vec), _deq(other._deq)
{}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_vec = other._vec;
		_deq = other._deq;
	}
	return *this;
}

void PmergeMe::parse(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		std::string arg = av[i];
		for (size_t j = 0; j < arg.length(); j++)
		{
			if (!isdigit(arg[j]))
				throw InvalidInputException();
		}
		long value = atol(av[i]);
		if (value > INT_MAX || value < INT_MIN)
			throw InvalidInputException();
		_vec.push_back(value);
		_deq.push_back(value);
	}
}

void PmergeMe::sort()
{
	std::cout << "Before: ";
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << _vec[i] << " ";
	std::cout << std::endl;

	clock_t start_vec = clock();
	mergeInsertSort(_vec);
	clock_t end_vec = clock();
	double time_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC * 1000000;

	clock_t start_deq = clock();
	mergeInsertSort(_deq);
	clock_t end_deq = clock();
	double time_deq = static_cast<double>(end_deq - start_deq) / CLOCKS_PER_SEC * 1000000;

	std::cout << "After:  ";
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << _vec[i] << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " << time_vec << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque  : " << time_deq << " us" << std::endl;
}

const char* PmergeMe::InvalidInputException::what() const throw()
{
	return "invalid input.";
}