/**
 * Generic Abstract Iterator.
 *
 * @file iterator/iterator.hpp
 *
 * @brief Implementation of a generic abstract iterator.
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

#ifndef DS_HPP_ITERATOR
#define DS_HPP_ITERATOR

namespace DS_HPP {
    template<typename T, typename Derived, typename Number = int>
    class Iterator;

}

/**
 * Represents a generic abstract interface.
 *
 * @tparam T - The type of elements.
 * @tparam Size - Class or primitive Size type for index representation (DEFAULT: int).
 */
template<typename T, typename Derived, typename Number>
class DS_HPP::Iterator {
protected:
    T *ptr;

public:
    explicit Iterator(T *ptr) : ptr(ptr) {}

    Iterator(const Iterator &iterator) : ptr(iterator.ptr) {}

    virtual Derived &operator+=(const Number &n) = 0;

    virtual Derived &operator-=(const Number &n) = 0;

    virtual Derived &operator++() = 0;

    virtual Derived &operator--() = 0;


    virtual Derived operator+(const Number &n) = 0;

    virtual Derived operator-(const Number &n) = 0;

    virtual T &operator*() const = 0;

    virtual bool operator==(const Derived &iterator) const = 0;

    virtual bool operator!=(const Derived &iterator) const = 0;

    virtual const Derived operator++(int) = 0;

    virtual const Derived operator--(int) = 0;

};

#endif
