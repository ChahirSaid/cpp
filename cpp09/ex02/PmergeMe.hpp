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

		template <typename T>
		void insertionSort(T& container)
		{
			for (size_t i = 1; i < container.size(); i++)
			{
				int key = container[i];
				int j = i - 1;
				while (j >= 0 && container[j] > key)
				{
					container[j + 1] = container[j];
					j--;
				}
				container[j + 1] = key;
			}
		}

		template <typename T>
		void mergeInsertSort(T& container)
		{
			if (container.size() <= 1)
				return;

			if (container.size() < 16)
			{
				insertionSort(container);
				return;
			}

			typename T::iterator mid = container.begin() + container.size() / 2;
			T left(container.begin(), mid);
			T right(mid, container.end());

			mergeInsertSort(left);
			mergeInsertSort(right);

			std::merge(left.begin(), left.end(), right.begin(), right.end(), container.begin());
		}

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