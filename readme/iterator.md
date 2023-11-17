# C++ Generic Linked List

Abstract interface of Iterator.

---

## Declaration

Supports >= c++11:

```c++
#include "iterator.hpp"

class Iterator : public DS_HPP::Iterator<T,Number,Iterator>;
```

## Template

```c++
/**
 * Represents a generic iterator abstract interface.
 *
 * @tparam T - The type of element.
 * @tparam Derived - The derived class implementing the iterator.
 * @tparam Size - Class or primitive Size type for index representation (DEFAULT: int).
 */
template<typename T, typename Derived, typename Number>
class DS_HPP::Iterator {
...
}
```

## Methods

Represents Hash Table (Double Hashing).

```cpp
/**
 * Constructor: Creates an iterator with a specific pointer to an element.
 *
 * @param ptr - Pointer to the element.
 *
 * @note Time Complexity: O(1) in the worst case.
 * @note Space Complexity: O(1) in the worst case.
 */
explicit Iterator(T *ptr);

/**
 * Copy Constructor: Creates an iterator from another iterator.
 *
 * @param iterator - Another iterator.
 *
 * @note Time Complexity: O(1) in the worst case.
 * @note Space Complexity: O(1) in the worst case.
 */
Iterator(const Iterator &iterator);

/**
 * Overloaded Operator += : Incrementally adds a Number to the iterator.
 *
 * @param n - The Number to be added.
 * @return A reference to the derived class object after the addition.
 *
 * @note Time Complexity: O(1) in the worst case.
 * @note Space Complexity: O(1) in the worst case.
 */
virtual Derived &operator+=(const Number &n);

/**
 * Overloaded Operator -= : Decreases the iterator by a specified Number.
 *
 * @param n - The Number to be subtracted.
 * @return A reference to the derived class object after the subtraction.
 *
 * @note Time Complexity: O(1) in the worst case.
 * @note Space Complexity: O(1) in the worst case.
 */
virtual Derived &operator-=(const Number &n);

/**
 * Overloaded Postfix Operator ++ : Increments the iterator and returns a copy of the original state.
 *
 * @return A new derived class object representing the original state before the increment.
 *
 * @note Time Complexity: O(1) in the worst case.
 * @note Space Complexity: O(1) in the worst case.
 */
virtual const Derived operator++(int);

/**
 * Overloaded Prefix Operator -- : Decrements the iterator.
 *
 * @return A reference to the derived class object after the decrement.
 *
 * @note Time Complexity: O(1) in the worst case.
 * @note Space Complexity: O(1) in the worst case.
 */
virtual Derived &operator--();

/**
 * Overloaded Postfix Operator -- : Decrements the iterator and returns a copy of the original state.
 *
 * @return A new derived class object representing the original state before the decrement.
 *
 * @note Time Complexity: O(1) in the worst case.
 * @note Space Complexity: O(1) in the worst case.
 */
virtual const Derived operator--(int);

/**
 * Overloaded Operator + : Adds a specified Number to the iterator and returns a new derived class object.
 *
 * @param n - The Number to be added.
 * @return A new derived class object representing the result of the addition.
 *
 * @note Time Complexity: O(1) in the worst case.
 * @note Space Complexity: O(1) in the worst case.
 */
virtual Derived operator+(const Number &n);

/**
 * Overloaded Operator - : Subtracts a specified Number from the iterator and returns a new derived class object.
 *
 * @param n - The Number to be subtracted.
 * @return A new derived class object representing the result of the subtraction.
 *
 * @note Time Complexity: O(1) in the worst case.
 * @note Space Complexity: O(1) in the worst case.
 */
virtual Derived operator-(const Number &n);

/**
 * Overloaded Operator * : Dereferences the iterator and returns a reference to the underlying object.
 *
 * @return A reference to the underlying object.
 *
 * @note Time Complexity: O(1) in the worst case.
 * @note Space Complexity: O(1) in the worst case.
 */
virtual T &operator*() const;

/**
 * Overloaded Operator == : Compares if the current iterator is equal to another iterator.
 *
 * @param iterator - The iterator to be compared.
 * @return True if the iterators are equal, false otherwise.
 *
 * @note Time Complexity: O(1) in the worst case.
 * @note Space Complexity: O(1) in the worst case.
 */
virtual bool operator==(const Derived &iterator) const;

/**
 * Overloaded Operator != : Compares if the current iterator is not equal to another iterator.
 *
 * @param iterator - The iterator to be compared.
 * @return True if the iterators are not equal, false otherwise.
 *
 * @note Time Complexity: O(1) in the worst case.
 * @note Space Complexity: O(1) in the worst case.
 */
virtual bool operator!=(const Derived &iterator) const;
```

## Author

[Liav Barsheshet, LBDevelopments](https://github.com/liavbarsheshet) © 2023

## License

[MIT](../LICENSE)
