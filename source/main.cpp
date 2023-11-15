#include <iostream>

#include "list.hpp"

int main() {
    DS_HPP::List<int> list1 = DS_HPP::List<int>({1, 2, 3, 4});
    DS_HPP::List<int> list2 = DS_HPP::List<int>({5, 6, 7, 8});
    DS_HPP::List<int> list3 = DS_HPP::List<int>({9, 10, 11, 12});
    DS_HPP::List<int> list = DS_HPP::List<int>::Concat();

    list.Splice(20,1,13);

    for (const auto &item: list) {
        std::cout << item << std::endl;
    }

    return 0;
}