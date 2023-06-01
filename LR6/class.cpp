#include <iostream>

template <typename T>
struct Element 
{
    T value;
    Element* prev;
    Element* next;
};

template <typename T>
class DoublyLinkedList 
{
private:
    Element<T>* head;
    Element<T>* tail;
    Element<T>* iterator;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), iterator(nullptr), size(0) {}
    ~DoublyLinkedList() { clear(); }

    int getSize() { return size; }

    Element<T>* find(const T& value) 
    {
        Element<T>* current = head;
        while (current != nullptr) 
        {
            if (current->value == value)
            {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    int getPosition(const T& value) 
    {
        Element<T>* current = head;
        int position = 0;
        while (current != nullptr) 
        {
            if (current->value == value)
            {
                return position;
            }
            current = current->next;
            position++;
        }
        return -1;
    }

    void insert(const T& value) 
    {
        Element<T>* newElement = new Element<T>;
        newElement->value = value;
        newElement->prev = nullptr;
        newElement->next = nullptr;

        if (size == 0) 
        {
            head = newElement;
            tail = newElement;
        }
        else 
        {
            tail->next = newElement;
            newElement->prev = tail;
            tail = newElement;
        }

        size++;
    }

    void clear() 
    {
        Element<T>* current = head;
        while (current != nullptr) 
        {
            Element<T>* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void setIteratorToBeginning() 
    {
        iterator = head;
    }

    bool isEndOfList() 
    {
        return iterator == nullptr;
    }

    T getCurrentValue() 
    {
        if (iterator != nullptr)
        {
            return iterator->value;
        }
        else
        {
            return T();
        }
    }

    void moveToPrevious() 
    {
        if (iterator != nullptr)
        {
            iterator = iterator->prev;
        }
    }

    void moveToNext() 
    {
        if (iterator != nullptr)
        {
            iterator = iterator->next;
        }
    }
};
