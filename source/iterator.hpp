/**
 * Generic Abstract Iterator.
 *
 * @file iterator.hpp
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
 * Represents a generic iterator abstract interface.
 *
 * @tparam T - The type of element.
 * @tparam Derived - The derived class implementing the iterator.
 * @tparam Size - Class or primitive Size type for index representation (DEFAULT: int).
 */
template<typename T, typename Derived, typename Number>
class DS_HPP::Iterator {
protected:
    T *ptr;

public:
    /**
     * Constructor: Creates an iterator with a specific pointer to an element.
     *
     * @param ptr - Pointer to the element.
     *
     * @note Time Complexity: O(1) in the worst case.
     * @note Space Complexity: O(1) in the worst case.
     */
    explicit Iterator(T *ptr) : ptr(ptr) {}

    /**
     * Copy Constructor: Creates an iterator from another iterator.
     *
     * @param iterator - Another iterator.
     *
     * @note Time Complexity: O(1) in the worst case.
     * @note Space Complexity: O(1) in the worst case.
     */
    Iterator(const Iterator &iterator) : ptr(iterator.ptr) {}

    /**
     * Overloaded Operator += : Incrementally adds a Number to the iterator.
     *
     * @param n - The Number to be added.
     * @return A reference to the derived class object after the addition.
     *
     * @note Time Complexity: O(1) in the worst case.
     * @note Space Complexity: O(1) in the worst case.
     */
    virtual Derived &operator+=(const Number &n) = 0;

    /**
     * Overloaded Operator -= : Decreases the iterator by a specified Number.
     *
     * @param n - The Number to be subtracted.
     * @return A reference to the derived class object after the subtraction.
     *
     * @note Time Complexity: O(1) in the worst case.
     * @note Space Complexity: O(1) in the worst case.
     */
    virtual Derived &operator-=(const Number &n) = 0;

    /**
     * Overloaded Prefix Operator ++ : Increments the iterator.
     *
     * @return A reference to the derived class object after the increment.
     *
     * @note Time Complexity: O(1) in the worst case.
     * @note Space Complexity: O(1) in the worst case.
     */
    virtual Derived &operator++() = 0;

    /**
     * Overloaded Postfix Operator ++ : Increments the iterator and returns a copy of the original state.
     *
     * @return A new derived class object representing the original state before the increment.
     *
     * @note Time Complexity: O(1) in the worst case.
     * @note Space Complexity: O(1) in the worst case.
     */
    virtual const Derived operator++(int) = 0;

    /**
     * Overloaded Prefix Operator -- : Decrements the iterator.
     *
     * @return A reference to the derived class object after the decrement.
     *
     * @note Time Complexity: O(1) in the worst case.
     * @note Space Complexity: O(1) in the worst case.
     */
    virtual Derived &operator--() = 0;

    /**
     * Overloaded Postfix Operator -- : Decrements the iterator and returns a copy of the original state.
     *
     * @return A new derived class object representing the original state before the decrement.
     *
     * @note Time Complexity: O(1) in the worst case.
     * @note Space Complexity: O(1) in the worst case.
     */
    virtual const Derived operator--(int) = 0;

    /**
     * Overloaded Operator + : Adds a specified Number to the iterator and returns a new derived class object.
     *
     * @param n - The Number to be added.
     * @return A new derived class object representing the result of the addition.
     *
     * @note Time Complexity: O(1) in the worst case.
     * @note Space Complexity: O(1) in the worst case.
     */
    virtual Derived operator+(const Number &n) = 0;

    /**
     * Overloaded Operator - : Subtracts a specified Number from the iterator and returns a new derived class object.
     *
     * @param n - The Number to be subtracted.
     * @return A new derived class object representing the result of the subtraction.
     *
     * @note Time Complexity: O(1) in the worst case.
     * @note Space Complexity: O(1) in the worst case.
     */
    virtual Derived operator-(const Number &n) = 0;

    /**
     * Overloaded Operator * : Dereferences the iterator and returns a reference to the underlying object.
     *
     * @return A reference to the underlying object.
     *
     * @note Time Complexity: O(1) in the worst case.
     * @note Space Complexity: O(1) in the worst case.
     */
    virtual T &operator*() const = 0;

    /**
     * Overloaded Operator == : Compares if the current iterator is equal to another iterator.
     *
     * @param iterator - The iterator to be compared.
     * @return True if the iterators are equal, false otherwise.
     *
     * @note Time Complexity: O(1) in the worst case.
     * @note Space Complexity: O(1) in the worst case.
     */
    virtual bool operator==(const Derived &iterator) const = 0;

    /**
     * Overloaded Operator != : Compares if the current iterator is not equal to another iterator.
     *
     * @param iterator - The iterator to be compared.
     * @return True if the iterators are not equal, false otherwise.
     *
     * @note Time Complexity: O(1) in the worst case.
     * @note Space Complexity: O(1) in the worst case.
     */
    virtual bool operator!=(const Derived &iterator) const = 0;
};

#endif
