#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "invalid number of arguments(!= 1)." << std::endl;
        return 1;
    }

    PmergeMe sorter;
    sorter.merge(argv);

    return 0;
}