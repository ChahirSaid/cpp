#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <iomanip>
#include <algorithm>

class PmergeMe
{
    private:
        std::vector<int> _vec;
        std::deque<int> _deq;

        void validateInput(char **argv);
        void printSequence(const std::string &prefix, const std::vector<int> &seq) const;
        std::vector<size_t> generateJacobsthal(size_t n);

        template <typename Container>
        void mergeInsertSort(Container &arr);

        void sortBoth(bool i);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        void merge(char **argv);
};