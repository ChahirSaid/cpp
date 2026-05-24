#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vec = other._vec;
        _list = other._list;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

template <typename T>
void PmergeMe::printContainer(const T& container, const std::string& name) {
    std::cout << name << ": ";
    for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::insertionSort(std::vector<int>& vec) {
    for (size_t i = 1; i < vec.size(); ++i) {
        int key = vec[i];
        size_t j = i;
        while (j > 0 && vec[j - 1] > key) {
            vec[j] = vec[j - 1];
            j--;
        }
        vec[j] = key;
    }
}

void PmergeMe::mergeInsertSort(std::vector<int>& vec) {
    if (vec.size() <= 1) return;

    if (vec.size() < 16) { 
        insertionSort(vec);
        return;
    }

    std::vector<std::pair<int, int> > pairs;
    int stray = -1;
    if (vec.size() % 2 != 0) {
        stray = vec[vec.size() - 1];
        vec.pop_back();
    }

    for (size_t i = 0; i < vec.size(); i += 2) {
        if (vec[i] > vec[i + 1]) {
            pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
        } else {
            pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
        }
    }

    std::vector<int> main_chain;
    std::vector<int> pend_elements;
    for (size_t i = 0; i < pairs.size(); ++i) {
        main_chain.push_back(pairs[i].first);
        pend_elements.push_back(pairs[i].second);
    }

    mergeInsertSort(main_chain);

    std::vector<int> jacobsthal_indices;
    int last_jacob = 1;
    int prev_jacob = 1;
    while( (size_t)last_jacob < pend_elements.size()){
        jacobsthal_indices.push_back(last_jacob);
        int temp = last_jacob;
        last_jacob = last_jacob + 2 * prev_jacob;
        prev_jacob = temp;
    }


    std::vector<int> insertion_order;
    size_t last_inserted = 0;
    for(size_t i = 0; i < jacobsthal_indices.size(); ++i){
        size_t end = jacobsthal_indices[i];
        if(end > pend_elements.size()){
            end = pend_elements.size();
        }
        for(size_t j = end; j > last_inserted; --j){
            insertion_order.push_back(j-1);
        }
        last_inserted = end;
    }


    for (size_t i = 0; i < insertion_order.size(); ++i) {
        int element_to_insert = pend_elements[insertion_order[i]];
        std::vector<int>::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), element_to_insert);
        main_chain.insert(it, element_to_insert);
    }

    if (stray != -1) {
        std::vector<int>::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), stray);
        main_chain.insert(it, stray);
    }

    vec = main_chain;
}


void PmergeMe::insertionSort(std::list<int>& lst) {
    if (lst.size() <= 1) return;
    std::list<int> sorted;
    if (!lst.empty()) {
        sorted.push_back(lst.front());
        lst.pop_front();
    }

    while (!lst.empty()) {
        int key = lst.front();
        lst.pop_front();
        std::list<int>::iterator it = sorted.begin();
        while (it != sorted.end() && *it < key) {
            ++it;
        }
        sorted.insert(it, key);
    }
    lst = sorted;
}

void PmergeMe::mergeInsertSort(std::list<int>& lst) {
    if (lst.size() <= 1) return;

    if (lst.size() < 16) {
        insertionSort(lst);
        return;
    }

    std::list<std::pair<int, int> > pairs;
    int stray = -1;
    if (lst.size() % 2 != 0) {
        stray = *(--lst.end());
        lst.pop_back();
    }

    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ) {
        int first = *it++;
        int second = *it++;
        if (first > second) {
            pairs.push_back(std::make_pair(first, second));
        } else {
            pairs.push_back(std::make_pair(second, first));
        }
    }

    std::list<int> main_chain;
    std::list<int> pend_elements;
    for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
        main_chain.push_back(it->first);
        pend_elements.push_back(it->second);
    }

    mergeInsertSort(main_chain);

    std::vector<int> jacobsthal_indices;
    int last_jacob = 1;
    int prev_jacob = 1;
    while( (size_t)last_jacob < pend_elements.size()){
        jacobsthal_indices.push_back(last_jacob);
        int temp = last_jacob;
        last_jacob = last_jacob + 2 * prev_jacob;
        prev_jacob = temp;
    }

    std::vector<int> insertion_order;
    size_t last_inserted = 0;
    for(size_t i = 0; i < jacobsthal_indices.size(); ++i){
        size_t end = jacobsthal_indices[i];
        if(end > pend_elements.size()){
            end = pend_elements.size();
        }
        for(size_t j = end; j > last_inserted; --j){
            insertion_order.push_back(j-1);
        }
        last_inserted = end;
    }

    for (size_t i = 0; i < insertion_order.size(); ++i) {
        std::list<int>::iterator pend_it = pend_elements.begin();
        std::advance(pend_it, insertion_order[i]);
        int element_to_insert = *pend_it;
        std::list<int>::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), element_to_insert);
        main_chain.insert(it, element_to_insert);
    }

    if (stray != -1) {
        std::list<int>::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), stray);
        main_chain.insert(it, stray);
    }

    lst = main_chain;
}


void PmergeMe::sortAndPrint(int argc, char** argv) {
    for (int i = 1; i < argc; ++i) {
        std::stringstream ss(argv[i]);
        int num;
        ss >> num;
        if (ss.fail() || num < 0) {
            std::cerr << "Error: Invalid input => " << argv[i] << std::endl;
            return;
        }
        _vec.push_back(num);
        _list.push_back(num);
    }

    std::cout << "Before: ";
    for (size_t i = 0; i < _vec.size(); ++i) {
        std::cout << _vec[i] << " ";
    }
    std::cout << std::endl;

    clock_t start_vec = clock();
    mergeInsertSort(_vec);
    clock_t end_vec = clock();
    double time_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC * 1000000;

    clock_t start_list = clock();
    mergeInsertSort(_list);
    clock_t end_list = clock();
    double time_list = static_cast<double>(end_list - start_list) / CLOCKS_PER_SEC * 1000000;

    std::cout << "After:  ";
    for (size_t i = 0; i < _vec.size(); ++i) {
        std::cout << _vec[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " << time_vec << " us" << std::endl;
    std::cout << "Time to process a range of " << _list.size() << " elements with std::list   : " << time_list << " us" << std::endl;
}
