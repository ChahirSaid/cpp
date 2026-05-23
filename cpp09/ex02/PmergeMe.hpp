/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 17:31:48 by schahir           #+#    #+#             */
/*   Updated: 2026/05/22 17:41:38 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <exception>
#include <climits>

class PmergeMe
{
	private:
		std::vector<int> _vec;
		std::deque<int> _deq;

		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);

		template <typename Container, typename PairContainer>
		void mergeInsertSort(Container& container);
		
		template <typename Container>
		void display(const Container& container, const std::string& str);

	public:
		PmergeMe();
		~PmergeMe();

		void parse(int ac, char **av);
		void sort();

		class InvalidInputException;
		
};

class PmergeMe::InvalidInputException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

#endif