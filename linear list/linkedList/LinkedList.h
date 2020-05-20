#pragma once

#include <iostream>

using namespace std;

template <typename T>
class LinkedList
{
private:
    class Node
    {
    public:
        T value;
        Node *next;
        Node(T item)
        {
            value = item;
            next = nullptr;
        }
    };

private:
    Node *pFirst;
    Node *pLast;
    int len;

private:
    // O(1)
    bool isEmpty()
    {
        return pFirst == nullptr;
    }

    // O(n)
    Node *getPrevious(Node *node)
    {
        Node *current = pFirst;
        while (current)
        {
            if (current->next == node)
                return current;
            current = current->next;
        }
        return nullptr;
    }

public:
    LinkedList();
    ~LinkedList();

public:
    // O(1)
    void addFirst(T item);
    // O(1)
    void addLast(T item);
    // O(1)
    void removeFirst();
    // O(n)
    void removeLast();
    // O(n)
    int indexOf(T item);
    // O(n)
    bool contains(T item);
    // O(1)
    int size();
    // O(n)
    T *toArray();
    // O(n)
    void reverse();
    // O(n)
    T getKthNodeFromTheEnd(int k);
    // O(n)
    void print();
};

template <typename T>
LinkedList<T>::LinkedList()
{
    pFirst = pLast = nullptr;
    len = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    while (pFirst)
    {
        Node *temp = pFirst->next;
        delete pFirst;
        pFirst = temp;
    }
}

template <typename T>
void LinkedList<T>::addFirst(T item)
{
    Node *node = new Node(item);

    if (isEmpty())
        pFirst = pLast = node;
    else
    {
        node->next = pFirst;
        pFirst = node;
    }
    len++;
}

template <typename T>
void LinkedList<T>::addLast(T item)
{
    Node *node = new Node(item);

    if (isEmpty())
        pFirst = pLast = node;
    else
    {
        pLast->next = node;
        pLast = node;
    }
    len++;
}

template <typename T>
void LinkedList<T>::removeFirst()
{
    if (isEmpty())
        throw "NoSuchElementException!";

    if (pFirst == pLast)
        pFirst = pLast = nullptr;
    else
    {
        Node *second = pFirst->next;
        delete pFirst;
        pFirst = second;
    }
}

template <typename T>
void LinkedList<T>::removeLast()
{
    if (isEmpty())
        throw "NoSuchElementException!";

    if (pFirst == pLast)
        pFirst = pLast = nullptr;
    else
    {
        Node *previous = getPrevious(pLast);
        delete pLast;
        pLast = previous;
        previous->next = nullptr;
    }
}

template <typename T>
int LinkedList<T>::indexOf(T item)
{
    Node *current = pFirst;
    for (int index = 0; index < len; index++)
    {
        if (current->value == item)
            return index;
        current = current->next;
    }

    return -1;
}

template <typename T>
bool LinkedList<T>::contains(T item)
{
    return indexOf(item) != -1;
}

template <typename T>
int LinkedList<T>::size()
{
    return len;
}

template <typename T>
T *LinkedList<T>::toArray()
{
    Node *current = pFirst;
    T *array = (T *)malloc(sizeof(T) * len);

    for (int i = 0; i < len; i++)
    {
        array[i] = current->value;
        current = current->next;
    }
    return array;
}

template <typename T>
void LinkedList<T>::reverse()
{
    if (isEmpty())
        return;

    Node *previous = pFirst;
    Node *current = pFirst->next;
    while (current != nullptr)
    {
        Node *next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    pLast = pFirst;
    pFirst = previous;
    pLast->next = nullptr;
}

template <typename T>
T LinkedList<T>::getKthNodeFromTheEnd(int k)
{
    if (isEmpty())
        throw "IllegalStateException";

    if (k > len)
        throw "IllegalArgumentException";

    Node *current = pFirst;
    Node *end = pFirst;
    for (int i = 0; i < k - 1; i++)
    {
        end = end->next;
        /*
        如果不知道链表的长度的话
        if (!end)
            throw "IllegalArgumentException";
        */
    }

    while (end->next != nullptr)
    {
        current = current->next;
        end = end->next;
    }

    return current->value;
}

template <typename T>
void LinkedList<T>::print()
{
    Node *current = pFirst;
    cout << "[ ";
    while (current)
    {
        cout << current->value << ' ';
        current = current->next;
    }
    cout << "]\n";
}