/**
 * Function Interfaces.
 *
 * @file functions.hpp
 *
 * @brief Implementation of an interfaces of functions object.
 *
 * @author Liav Barsheshet, liavbarsheshet@gmail.com
 * @copyright LB Developments © 2023
 *
 * This implementation is free: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This implementation is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

//TODO: Add documentation.

#include<cstdlib>
#include <random>

#include "exceptions.hpp"

#ifndef DS_HPP_FUNCTIONS
#define DS_HPP_FUNCTIONS
namespace DS_HPP {
    template<typename T>
    class FilterFunction;

    typedef enum {
        SORT_SMALLER = -1, SORT_EQUAL, SORT_BIGGER,
    } SortResult;

    template<typename T>
    class SortFunction;

    template<typename T>
    class RandomFunction;
}

template<typename T>
class DS_HPP::FilterFunction {
public:
    virtual bool operator()(const T &) const = 0;
};

template<typename T>
class DS_HPP::SortFunction {
public:
    virtual DS_HPP::SortResult operator()(const T &a, const T &b) const {
        if (a < b) return SORT_SMALLER;
        if (a > b) return SORT_BIGGER;
        return SORT_EQUAL;
    };
};

template<typename Number>
class DS_HPP::RandomFunction {
public:
    virtual void operator()(const size_t &min, const size_t &max, size_t &output) const {

        if (min < 0 || max < min)
            throw DS_HPP::EXC::InvalidInput("Invalid min or max.");

        if (max == min) {
            output = min;
            return;
        }

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<Number> dist(min, max - 1);
        output = dist(gen);
        return;
    };

    virtual void operator()(const Number &min, const Number &max, Number &output) const;
};

#endif
