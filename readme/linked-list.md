# C++ Generic Linked List

Implementation of a Generic bi-derction Linked List.

---

## Declaration

Supports >= c++11:

```c++
#include "linked-list.hpp"

DS_HPP::ListNode<typename T, typename Size> list;
```

## Template

```c++
/**
 * Represents a generic bi-direction linked list data structure.
 *
 * @tparam T - The type of items.
 * @tparam Size - Class or primitive Size type for index representation (DEFAULT: size_t).
 */
template<typename T, typename Size>
class DS_HPP::List {
...
}
```

## Methods

```cpp
/**
 * Constructor: Initializes an empty linked list.
 *
 * @note Worst-Time Complexity: O(1).
 * @note Worst-Space Complexity: O(1).
 */
List();

/**
 * Constructor: Initializes with list.
 *
 * @param items Initializer list of items.
 *
 * @note Worst-Time Complexity: O(n).
 * @note Worst-Space Complexity: O(n).
 */
List(const std::initializer_list<T> &items);

/**
 * Copy Constructor: Creates a copy from a given linked list.
 *
 * @param list - Linked list to be copied.
 * @note Worst-Time Complexity: O(n).
 * @note Worst-Space Complexity: O(n).
 */
List(const List &list);

/**
 * Clears the entire list.
 *
 * @note Worst-Time Complexity: O(n).
 * @note Worst-Space Complexity: O(1).
 */
void Clear();

/**
 * Destructor: Deallocates the entire list.
 *
 * @note Worst-Time Complexity: O(n).
 * @note Worst-Space Complexity: O(1).
 */
~List();

/**
 * Checks if the list is empty.
 *
 * @note Worst-Time Complexity: O(1).
 * @note Worst-Space Complexity: O(1).
 * @return true if it's empty, otherwise false.
 */
[[nodiscard]] bool IsEmpty() const;

/**
 * Retrieves the length of the linked list.
 *
 * @note Worst-Time Complexity: O(1).
 * @note Worst-Space Complexity: O(1).
 * @return The length of the linked list.
 */
Size Length() const;

/**
 * Appends an item to the end of the linked list.
 *
 * @param item - The new item to be inserted.
 *
 * @note Worst-Time Complexity: O(1).
 * @note Worst-Space Complexity: O(1).
 */
void Append(const T &item);

/**
 * Appends an item to the start of the linked list.
 *
 * @param item - The new item to be inserted.
 * @note Worst-Time Complexity: O(1).
 * @note Worst-Space Complexity: O(1).
 */
void Prepend(const T &item);

/**
 * Inserts a new item into the list after a specific item pointed to by the iterator.
 *
 * @param iterator - Iterator pointing to a specific item.
 * @param item - The new item to be inserted.
 * @note Worst-Time Complexity: O(1).
 * @note Worst-Space Complexity: O(1).
 */
void InsertAfter(const Iterator &iterator, const T &item);

/**
 * Inserts a new item into the list after a specific item by index.
 *
 * @param index - Index of an item.
 * @param item - The new item to be inserted.
 * @note Worst-Time Complexity: O(n).
 * @note Worst-Space Complexity: O(1).
*/
void InsertAfter(const Size &index, const T &item);

/**
 * Inserts a new item into the list before a specific item pointed to by the iterator.
 *
 * @param iterator - Iterator pointing to a specific item.
 * @param item - The new item to be inserted.
 * @note Worst-Time Complexity: O(1).
 * @note Worst-Space Complexity: O(1).
 */
void InsertBefore(const Iterator &iterator, const T &item);


/**
 * Inserts a new item into the list before a specific item by index.
 *
 * @param index - Index of an item.
 * @param item - The new item to be inserted.
 * @note Worst-Time Complexity: O(n).
 * @note Worst-Space Complexity: O(1).
 */
void InsertBefore(const Size &index, const T &item);

/**
 * Removes an item from the list pointed to by the iterator.
 *
 * @param iterator - Iterator pointing to a specific item.
 * @param removed_item - Pointer to save the removed item.
 * @note The iterator will not be usable afterward.
 * @note Worst-Time Complexity: O(n).
 * @note Worst-Space Complexity: O(1).
 */
void Remove(Iterator &iterator, T *removed_item = nullptr);

/**
 * Removes an item from the list given specific index.
 *
 * @param index - Index of an item.
 * @param removed_item - Pointer to save the removed item.
 * @note The iterator will not be usable afterward.
 * @note Worst-Time Complexity: O(n).
 * @note Worst-Space Complexity: O(1).
 */
void Remove(const Size &index, T *removed_item = nullptr);

/**
 * Retrieves the item at a specific index.
 *
 * @param index - The specific index of an item.
 * @note Worst-Time Complexity: O(n).
 * @note Worst-Space Complexity: O(1).
 * @return The item at the specified index.
 */
T operator[](const Size &index) const;

/**
 * Retrieves the item at a specific index.
 *
 * @param index - The specific index of an item.
 * @note Worst-Time Complexity: O(n).
 * @note Worst-Space Complexity: O(1).
 * @return The item at the specified index.
 */
T &
operator[](const Size &index);

/**
 * Joins the current linked list with another list.
 *
 * @param list - Linked list to be joined.
 *
 * @note Time Complexity: O(n) in the worst case, where n is the number of elements in the given list.
 * @note Space Complexity: O(n) in the worst case.
 */
void Join(const List<T, Size> &list);

/**
 * Changes the contents of the list by removing or replacing existing elements and/or adding new elements in place.
 *
 * @param from Starting index.
 * @param delete_count The amount of items to be deleted from the index.
 * @param ...[items] - Items to be added.
 *
 * @note Time Complexity: O(n + items).
 * @note Space Complexity: O(items).
 */
void Splice(const Size &from, const Size &delete_count, const Args &... item);

/**
 * removes the first item from the list.
 *
 * @note Time Complexity: O(1).
 * @note Space Complexity: O(1).
 */
T Shift();

/**
 * Create a reversed linked list from this list.
 *
 * @note Time Complexity: O(n).
 * @note Space Complexity: O(n).
 */
List<T, Size> Reverse() const;

/**
 * Checks if a specific item exists within the linked list.
 *
 * @param item - The item to be checked.
 *
 * @note Time Complexity: O(n) in the worst case.
 * @note Space Complexity: O(n) in the worst case.
 */
bool Contains(const T &item) const;

/**
 * Represents an iterator for a linked list.
 */
class Iterator;

/**
 * Creates an iterator at the beginning of the linked list.
 *
 * @return Iterator at the beginning of the list.
 */
Iterator begin() const;

/**
 * Returns the end of the iterator.
 *
 * @return Iterator pointing to the end.
 */
Iterator end() const;

/**
 * Creates a reversed iterator at the beginning of the linked list.
 *
 * @return Iterator at the end of the list.
 */
Iterator rbegin() const;

/**
 * Returns the end of the reversed iterator.
 *
 * @return Iterator pointing to the end.
 */
Iterator rend() const
```

## Author

[Liav Barsheshet, LBDevelopments](https://github.com/liavbarsheshet) © 2023

## License

[MIT](../LICENSE)
