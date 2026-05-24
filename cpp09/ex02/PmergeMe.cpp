#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) : _vec(other._vec), _deq(other._deq)
{}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _vec = other._vec;
        _deq = other._deq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::validateInput(char **argv)
{
    for (int i = 1; argv[i]; ++i)
    {
        std::string arg = argv[i];
        if (arg.empty())
            throw std::runtime_error("empty string provided.");

        size_t start = 0;

        if (arg[0] == '+')
            start++;

        for (size_t j = start; j < arg.length(); ++j)
        {
            if (!isdigit(arg[j]))
            {
                throw std::runtime_error("Must be positive integers.");
            }
        }

        long val = std::atol(arg.c_str());
        if (val < 0 || val > INT_MAX)
            throw std::runtime_error("Must be positive integers.");

        _vec.push_back(static_cast<int>(val));
        _deq.push_back(static_cast<int>(val));
    }
}

void PmergeMe::printSequence(const std::string &prefix, const std::vector<int> &seq) const
{
    std::cout << prefix;

    for (size_t i = 0; i < seq.size(); ++i)
    {
        std::cout << seq[i] << " ";
    }
    std::cout << std::endl;
}

std::vector<size_t> PmergeMe::generateJacobsthal(size_t n)
{
    std::vector<size_t> jacob;
    std::vector<size_t> sequence;
    if (n == 0)
        return sequence;

    jacob.push_back(0);
    jacob.push_back(1);

    while (true)
    {
        size_t next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
        jacob.push_back(next);
        if (next > n)
            break;
    }

    size_t last_j = 1;
    for (size_t i = 3; i < jacob.size(); ++i)
    {
        size_t j = jacob[i];
        if (j > n)
            j = n;

        for (size_t k = j; k > last_j; --k)
        {
            sequence.push_back(k - 1);
        }
        last_j = j;
        if (j == n)
            break;
    }
    return sequence;
}

static bool comparePairs(const std::pair<int, int> &a, const std::pair<int, int> &b)
{
    return a.first < b.first;
}

template <typename Container>
void PmergeMe::mergeInsertSort(Container &arr)
{
    if (arr.size() <= 1)
        return;

    bool hasStraggler = (arr.size() % 2 != 0);
    int straggler = 0;
    if (hasStraggler)
    {
        straggler = arr.back();
        arr.pop_back();
    }

    std::vector<std::pair<int, int>> pairs;
    for (size_t i = 0; i < arr.size(); i += 2)
    {
        int first = arr[i];
        int second = arr[i + 1];
        pairs.push_back(std::make_pair(std::max(first, second), std::min(first, second)));
    }

    std::sort(pairs.begin(), pairs.end(), comparePairs);

    Container mainChain;
    Container pendChain;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        mainChain.push_back(pairs[i].first);
        pendChain.push_back(pairs[i].second);
    }

    mainChain.insert(mainChain.begin(), pendChain[0]);

    std::vector<size_t> jacobSeq = generateJacobsthal(pendChain.size());
    for (size_t i = 0; i < jacobSeq.size(); ++i)
    {
        size_t idx = jacobSeq[i];
        if (idx == 0)
            continue;

        int value = pendChain[idx];
        typename Container::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), value);
        mainChain.insert(pos, value);
    }

    if (hasStraggler)
    {
        typename Container::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }

    arr = mainChain;
}

void PmergeMe::sortBoth(bool i)
{
    if (i)
        mergeInsertSort(_vec);
    else
        mergeInsertSort(_deq);
}

void PmergeMe::merge(char **argv)
{
    try
    {
        validateInput(argv);
        printSequence("Before:\t", _vec);

        std::clock_t start = std::clock();
        sortBoth(1);
        std::clock_t end = std::clock();
        double vecTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;

        start = std::clock();
        sortBoth(0);
        end = std::clock();
        double deqTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;

        printSequence("After:\t", _vec);

        std::cout << "Time to process a range of " << _vec.size()
                  << " elements with std::vector : " << vecTime << " us" << std::endl;

        std::cout << "Time to process a range of " << _deq.size()
                  << " elements with std::deque  : " << deqTime << " us" << std::endl;
    }
    catch (...)
    {
        std::cerr << "Unexpected error occurred." << std::endl;
    }
}