/**
 * Generic Linked List.
 *
 * @file list.hpp
 *
 * @brief Implementation of a generic bi-directional linked list.
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

#include <type_traits>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "exceptions.hpp"
#include "functions.hpp"
#include "iterator.hpp"

#ifndef DS_HPP_LIST
#define DS_HPP_LIST

namespace DS_HPP {
    template<typename T>
    class ListNode;

    template<typename T, typename Size = size_t>
    class List;
}

/**
 * Represents a node in a linked list.
 */
template<typename T>
class DS_HPP::ListNode {
public:
    T data;
    ListNode<T> *next;
    ListNode<T> *prev;

    explicit ListNode(const T &data) : data(data), next(nullptr), prev(nullptr) {}
};

/**
 * Represents a generic bi-direction linked list data structure.
 *
 * @tparam T - The type of items.
 * @tparam Size - Class or primitive Size type for index representation (DEFAULT: size_t).
 */
template<typename T, typename Size>
class DS_HPP::List {

private:
    DS_HPP::ListNode<T> *start;
    DS_HPP::ListNode<T> *last;
    Size *length;

public:
    /**
     * Represents an iterator for a linked list.
     */
    class Iterator : public DS_HPP::Iterator<T, Iterator, Size> {
    public:
        friend class List;

    private:
        DS_HPP::ListNode<T> *current;
        bool reversed;

    public:
        explicit Iterator(DS_HPP::ListNode<T> *current, bool revered = false) : DS_HPP::Iterator<T, Iterator, Size>(
                current ? &current->data : nullptr), current(current), reversed(revered) {}

        Iterator(const Iterator &iterator) : DS_HPP::Iterator<T, Iterator, Size>(iterator.ptr),
                                             current(iterator.current),
                                             reversed(iterator.reversed) {}

        T &operator*() const override {
            if (!this->current)
                throw DS_HPP::EXC::UndefinedReference();
            return (*this->ptr);
        }

        // Prefix Increment
        Iterator &operator++() override {
            if (this->current) {
                this->current = this->reversed ? this->current->prev : this->current->next;
                this->ptr = this->current ? (&this->current->data) : nullptr;
            }

            return *this;
        }

        // Postfix Increment
        const Iterator operator++(int) override {
            Iterator tmp = *this;
            this->operator++();
            return tmp;
        };

        // Prefix Decrement
        Iterator &operator--() override {
            DS_HPP::ListNode<T> *tmp;
            if (this->current) {
                tmp = this->reversed ? this->current->next : this->current->prev;

                if (tmp) {
                    this->current = tmp;
                    this->ptr = (&this->current->data);
                }
            }

            return *this;
        }

        // Postfix Decrement
        const Iterator operator--(int) override {
            Iterator tmp = *this;
            this->operator--();
            return tmp;
        }

        Iterator &operator+=(const Size &n) override {
            for (Size i = 0; i < n && this->current; ++i) {
                this->operator++();
            }

            return *this;
        }

        Iterator &operator-=(const Size &n) override {
            for (Size i = 0; i < n && this->current; ++i) {
                this->operator--();
            }

            return *this;
        }

        Iterator operator+(const Size &n) override {
            Iterator tmp = *this;
            tmp += n;
            return tmp;
        }

        Iterator operator-(const Size &n) override {
            Iterator tmp = *this;
            tmp -= n;
            return tmp;
        }

        bool operator!=(const Iterator &iterator) const override {
            return (
                    iterator.ptr != this->ptr ||
                    iterator.current != this->current ||
                    iterator.reversed != this->reversed);
        }

        bool operator==(const Iterator &iterator) const override {
            return !(this->operator!=(iterator));
        }
    };

    /**
     * Creates an iterator at the beginning of the linked list.
     *
     * @return Iterator at the beginning of the list.
     */
    Iterator begin() const {
        return Iterator(this->start);
    }

    /**
     * Creates a reversed iterator at the beginning of the linked list.
     *
     * @return Iterator at the end of the list.
     */
    Iterator rbegin() const {
        return Iterator(this->last, true);
    }

    /**
     * Returns the end of the iterator.
     *
     * @return Iterator pointing to the end.
     */
    Iterator end() const {
        return Iterator(nullptr);
    }

    /**
     * Returns the end of the reversed iterator.
     *
     * @return Iterator pointing to the end.
     */
    Iterator rend() const {
        return Iterator(nullptr, true);
    }

private:
    Iterator Find(const Size &index) const {
        if (index >= (*this->length) || index < 0)
            throw DS_HPP::EXC::IndexOutOfRange();

        Iterator it = this->begin();

        return it + index;
    }

public:
    /**
     * Constructor: Initializes an empty linked list.
     *
     * @note Worst-Time Complexity: O(1).
     * @note Worst-Space Complexity: O(1).
     */
    List() : start(nullptr), last(nullptr), length(new Size(0)) {}

    /**
     * Constructor: Initializes with list.
     *
     * @param items Initializer list of items.
     *
     * @note Worst-Time Complexity: O(n).
     * @note Worst-Space Complexity: O(n).
     */
    List(const std::initializer_list<T> &items) : start(nullptr), last(nullptr), length(new Size(0)) {
        for (const T &item: items) {
            this->Append(item);
        }
    }

    /**
     * Copy Constructor: Creates a copy from a given linked list.
     *
     * @param list - Linked list to be copied.
     * @note Worst-Time Complexity: O(n).
     * @note Worst-Space Complexity: O(n).
     */
    List(const List &list) : start(nullptr), last(nullptr), length(new Size(0)) {
        for (const auto &item: list) {
            this->Append(item);
        }
    }

    /**
     * Clears the entire list.
     *
     * @note Worst-Time Complexity: O(n).
     * @note Worst-Space Complexity: O(1).
     */
    void Clear() {
        DS_HPP::ListNode<T> *head = this->start;
        DS_HPP::ListNode<T> *tmp;

        while (head) {
            tmp = head->next;
            delete head;
            head = tmp;
        }

        (*this->length) = 0;
    }

    /**
     * Destructor: Deallocates the entire list.
     *
     * @note Worst-Time Complexity: O(n).
     * @note Worst-Space Complexity: O(1).
     */
    ~List() {
        this->Clear();
        delete this->length;
    }

    /**
     * Checks if the list is empty.
     *
     * @note Worst-Time Complexity: O(1).
     * @note Worst-Space Complexity: O(1).
     * @return true if it's empty, otherwise false.
     */
    [[nodiscard]] bool
    IsEmpty() const {
        return (*this->length == 0);
    }

    /**
     * Retrieves the length of the linked list.
     *
     * @note Worst-Time Complexity: O(1).
     * @note Worst-Space Complexity: O(1).
     * @return The length of the linked list.
     */
    Size
    Length() const {
        return (*this->length);
    }

    /**
     * Appends an item to the end of the linked list.
     *
     * @param item - The new item to be inserted.
     *
     * @note Worst-Time Complexity: O(1).
     * @note Worst-Space Complexity: O(1).
     */
    void
    Append(const T &item) {
        auto *new_node = new DS_HPP::ListNode<T>(item);

        if (this->IsEmpty()) {
            this->start = new_node;
            this->last = new_node;
        } else {
            this->last->next = new_node;
            new_node->prev = this->last;
            this->last = new_node;
        }

        ++(*this->length);


    }

    /**
     * Appends an item to the start of the linked list.
     *
     * @param item - The new item to be inserted.
     * @note Worst-Time Complexity: O(1).
     * @note Worst-Space Complexity: O(1).
     */
    void Prepend(const T &item) {
        auto *new_node = new DS_HPP::ListNode<T>(item);

        if (this->IsEmpty()) {
            this->start = new_node;
            this->last = new_node;
            return;
        } else {
            new_node->next = this->start;
            this->start->prev = new_node;
            this->start = new_node;
        }

        ++(*this->length);
    }

    /**
     * Inserts a new item into the list after a specific item pointed to by the iterator.
     *
     * @param iterator - Iterator pointing to a specific item.
     * @param item - The new item to be inserted.
     * @note Worst-Time Complexity: O(1).
     * @note Worst-Space Complexity: O(1).
     */
    void InsertAfter(const Iterator &iterator, const T &item) {
        DS_HPP::ListNode<T> *current = iterator.current;

        if (!iterator.current || !current->next) {
            this->Append(item);
            return;
        }

        auto *new_node = new DS_HPP::ListNode<T>(item);

        // Connecting the new node.
        new_node->prev = current;
        new_node->next = current->next;

        // Updating connection.
        current->next->prev = new_node;
        current->next = new_node;

        ++(*this->length);
    }

    /**
     * Inserts a new item into the list after a specific item by index.
     *
     * @param index - Index of an item.
     * @param item - The new item to be inserted.
     * @note Worst-Time Complexity: O(n).
     * @note Worst-Space Complexity: O(1).
    */
    void InsertAfter(const Size &index, const T &item) {
        Iterator iterator = this->Find(index);
        this->InsertAfter(iterator, item);
    }

    /**
     * Inserts a new item into the list before a specific item pointed to by the iterator.
     *
     * @param iterator - Iterator pointing to a specific item.
     * @param item - The new item to be inserted.
     * @note Worst-Time Complexity: O(1).
     * @note Worst-Space Complexity: O(1).
     */
    void InsertBefore(const Iterator &iterator, const T &item) {
        DS_HPP::ListNode<T> *current = iterator.current;

        if (!iterator.current || !current->prev) {
            this->Prepend(item);
            return;
        }

        auto *new_node = new DS_HPP::ListNode<T>(item);

        // Connecting the new node.
        new_node->next = current;
        new_node->prev = current->prev;

        // Updating connection.
        current->prev->next = new_node;
        current->prev = new_node;

        ++(*this->length);
    }

    /**
     * Inserts a new item into the list before a specific item by index.
     *
     * @param index - Index of an item.
     * @param item - The new item to be inserted.
     * @note Worst-Time Complexity: O(n).
     * @note Worst-Space Complexity: O(1).
     */
    void InsertBefore(const Size &index, const T &item) {
        Iterator iterator = this->Find(index);
        this->InsertBefore(iterator, item);
    }

    /**
     * Removes an item from the list pointed to by the iterator.
     *
     * @param iterator - Iterator pointing to a specific item.
     * @param removed_item - Pointer to save the removed item.
     * @note The iterator will not be usable afterward.
     * @note Worst-Time Complexity: O(n).
     * @note Worst-Space Complexity: O(1).
     */
    void Remove(Iterator &iterator, T *removed_item = nullptr) {
        if (!iterator.current)
            return;

        if (iterator.current->next) {
            iterator.current->next->prev = iterator.current->prev;
        }
        if (iterator.current->prev) {
            iterator.current->prev->next = iterator.current->next;
        }

        --(*this->length);

        if (this->IsEmpty()) {
            this->start = nullptr;
            this->last = nullptr;
        }

        if (removed_item) {
            (*removed_item) = *iterator;
        }

        delete (iterator++).current;
    }

    /**
     * Removes an item from the list given specific index.
     *
     * @param index - Index of an item.
     * @param removed_item - Pointer to save the removed item.
     * @note The iterator will not be usable afterward.
     * @note Worst-Time Complexity: O(n).
     * @note Worst-Space Complexity: O(1).
     */
    void Remove(const Size &index, T *removed_item = nullptr) {
        Iterator iterator = this->Find(index);
        this->Remove(iterator, removed_item);
    }

    /**
     * Retrieves the item at a specific index.
     *
     * @param index - The specific index of an item.
     * @note Worst-Time Complexity: O(n).
     * @note Worst-Space Complexity: O(1).
     * @return The item at the specified index.
     */
    T operator[](const Size &index) const {
        return (*this->Find(index));
    }

    /**
     * Retrieves the item at a specific index.
     *
     * @param index - The specific index of an item.
     * @note Worst-Time Complexity: O(n).
     * @note Worst-Space Complexity: O(1).
     * @return The item at the specified index.
     */
    T &
    operator[](const Size &index) {
        return (*this->Find(index));
    }

    // Special Methods

    /**
     * Joins the current linked list with another list.
     *
     * @param list - Linked list to be joined.
     *
     * @note Time Complexity: O(n) in the worst case, where n is the number of elements in the given list.
     * @note Space Complexity: O(n) in the worst case.
     */
    void Join(const List<T, Size> &list) {
        for (const auto &item: list) {
            this->Append(item);
        }
    }

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
    template<typename ... Args>
    void Splice(const Size &from, const Size &delete_count, const Args &... item) {
        Iterator it = from >= (*this->length) ? Iterator(nullptr) : this->Find(from);

        if (!it.current) {
            (this->Append(item), ...);
            return;
        }

        (this->InsertBefore(it, item), ...);

        if (delete_count <= 0) return;

        for (Size i = 0; i < delete_count; ++i) {
            this->Remove(it);
        }
    }

    /**
     * removes the first item from the list.
     *
     * @note Time Complexity: O(1).
     * @note Space Complexity: O(1).
     */
    T Shift() {
        T removed_item;
        this->Remove(this->begin(), &removed_item);
        return removed_item;
    }

    /**
     * Create a reversed linked list from this list.
     *
     * @note Time Complexity: O(n).
     * @note Space Complexity: O(n).
     */
    List<T, Size> Reverse() const {
        List<T, Size> list;

        for (const auto &it = this->rbegin(); it != this->rend(); ++it) {
            list.Append(*it);
        }

        return list;
    }

    /**
     * Checks if a specific item exists within the linked list.
     *
     * @param item - The item to be checked.
     *
     * @note Time Complexity: O(n) in the worst case..
     * @note Space Complexity: O(n) in the worst case.
     */
    bool Contains(const T &item) const {

        for (const auto &_item: *this) {
            if (_item != item) continue;
            return true;
        }

        return false;

    }

    //TODO: Documentation.
    List<T, Size> Filter(const DS_HPP::FilterFunction<T> &filter_function) const {
        List<T, Size> filtered_list;

        for (auto item: *this) {
            if (filter_function(item)) filtered_list.Append(item);
        }

        return filtered_list;
    }

    List<T, Size> Shuffle(const DS_HPP::RandomFunction<T> &random_function) const {
        List<T, Size> list = List<T, Size>(*this);
        Size i = 0, random_index;

        while (i < list.length) {
            random_function(i, list.length, random_index);
            T temp = list[random_index];
            list[random_index] = list[i];
            list[i] = temp;
            ++i;
        }

        return list;
    }

    List<T, Size> Sort(const DS_HPP::SortFunction<T> &sort_function) const {
        // TODO: Implement
        List<T, Size> list = List<T, Size>(*this);

        return list;
    }

    // Static Methods

    /**
     * Concatenates multiple linked lists into one.
     *
     * @param ...[lists] - List of linked lists to be concatenated.
     *
     * @note Time Complexity: O(m*n) in the worst case, where m is the number of lists and n is the total number of elements.
     * @note Space Complexity: O(m*n) in the worst case.
     * @note Static method.
     */
    template<typename ... Args>
    static List<T, Size> Concat(const Args &... args) {

        auto result = List<T, Size>();

        (result.Join(args), ...);

        return result;
    }
};

#endif