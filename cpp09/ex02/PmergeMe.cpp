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

void generateJacobsthalSequence(std::vector<int>& sequence, int size) {
    if (size <= 0) return;
    sequence.push_back(0);
    if (size <= 1) return;
    sequence.push_back(1);
    int a = 0, b = 1;
    while (true) {
        int next = b + 2 * a;
        if (next >= size) break;
        sequence.push_back(next);
        a = b;
        b = next;
    }
}

template <typename Container, typename PairContainer>
void PmergeMe::mergeInsertSort(Container& container) {
    if (container.size() <= 1) {
        return;
    }

    bool hasStraggler = container.size() % 2 != 0;
    int straggler = 0;
    if (hasStraggler) {
        straggler = container.back();
        container.pop_back();
    }

    PairContainer pairs;
    pairs.reserve(container.size() / 2);
    for (size_t i = 0; i < container.size(); i += 2) {
        if (container[i] > container[i + 1]) {
            pairs.push_back(std::make_pair(container[i], container[i + 1]));
        } else {
            pairs.push_back(std::make_pair(container[i + 1], container[i]));
        }
    }

    std::sort(pairs.begin(), pairs.end());

    Container mainChain;
    Container pend;
    mainChain.reserve(pairs.size() + 1 + (hasStraggler ? 1 : 0));
    pend.reserve(pairs.size());

    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }

    if (!pend.empty()) {
        mainChain.insert(mainChain.begin(), pend[0]);
    }

    std::vector<int> jacobSequence;
    generateJacobsthalSequence(jacobSequence, pend.size());

    size_t lastInserted = 1;
    for (size_t i = 2; i < jacobSequence.size(); ++i) {
        size_t end = jacobSequence[i];
        if (end >= pend.size()) {
            end = pend.size() -1;
        }
        for (size_t j = end; j > lastInserted; --j) {
            typename Container::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pend[j]);
            mainChain.insert(it, pend[j]);
        }
        lastInserted = end;
    }
     for (size_t j = pend.size() - 1; j > lastInserted; --j) {
        typename Container::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pend[j]);
        mainChain.insert(it, pend[j]);
    }


    if (hasStraggler) {
        typename Container::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(it, straggler);
    }

    container = mainChain;
}

template <typename Container>
void PmergeMe::display(const Container& container, const std::string& str)
{
	std::cout << str;
	for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

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
		std::stringstream ss(arg);
		int value;
		char c;
		if (!(ss >> value) || (ss >> c))
			throw InvalidInputException();
		if (value < 0)
			throw InvalidInputException();
		_vec.push_back(value);
		_deq.push_back(value);
	}
}

void PmergeMe::sort()
{
	display(_vec, "Before: ");

	clock_t start_vec = clock();
	mergeInsertSort<std::vector<int>, std::vector<std::pair<int, int> > >(_vec);
	clock_t end_vec = clock();
	double time_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC * 1000000;

	clock_t start_deq = clock();
	mergeInsertSort<std::deque<int>, std::deque<std::pair<int, int> > >(_deq);
	clock_t end_deq = clock();
	double time_deq = static_cast<double>(end_deq - start_deq) / CLOCKS_PER_SEC * 1000000;

	display(_vec, "After:  ");

	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " << time_vec << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque  : " << time_deq << " us" << std::endl;
}

const char* PmergeMe::InvalidInputException::what() const throw()
{
	return "Error: invalid input.";
}
