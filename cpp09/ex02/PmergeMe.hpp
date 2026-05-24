#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include <algorithm>
#include <ctime>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void sortAndPrint(int argc, char** argv);

private:
    std::vector<int> _vec;
    std::list<int> _list;

    template <typename T>
    void printContainer(const T& container, const std::string& name);

    void mergeInsertSort(std::vector<int>& vec);
    void insertionSort(std::vector<int>& vec);

    void mergeInsertSort(std::list<int>& lst);
    void insertionSort(std::list<int>& lst);
};

#endif 
