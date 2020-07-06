#ifndef TEST_stack_H
#define TEST_stack_H
#include <iostream>
using namespace std;

template <class T>
class stack {
    public:
        stack ();
        stack (stack const&);
        ~stack ();

        bool isOverFlow ();
        bool empty ();

        void push(const T newItem);
        void pop();
        T    top();

        unsigned getSize ();

        void print ();
        void resize ();

    private:
        unsigned sizeOfstack_;
        unsigned capacity_ = 10;
        T*       array_;
};

#include "stack.h"


template <class T>
stack<T>::stack() {
    array_ = new T[capacity_];
    sizeOfstack_ = 0;
}



template<class T>
stack<T>::stack(stack const& copy) {
    sizeOfstack_ = copy.sizeOfstack_;
    array_ = copy.array_;
}



template<class T>
stack<T>::~stack() {
    if (array_) {
        delete[] array_;

        array_ = nullptr;
        sizeOfstack_ = 0;
        capacity_ = 10;
    }
}



template<class T>
bool stack<T>::isOverFlow() {
    return sizeOfstack_ == capacity_;
}



template<class T>
bool stack<T>::empty() {
    return sizeOfstack_ == 0;
}



template<class T>
void stack<T>::resize() {
    capacity_ = sizeOfstack_ * int((1 + sqrt(5))) / 2;
    T* tempstack = new T[capacity_];

    for (int i = 0; i < sizeOfstack_; i++) {
        tempstack[i] = array_[i];
    }

    delete[] array_;
    array_ = new T[capacity_];

    for (int i = 0; i < sizeOfstack_; i++) {
        array_[i] = tempstack[i];
    }

    delete[] tempstack;
}



template<class T>
void stack<T>::push(const T newItem) {
    if (isOverFlow()) {
        resize();
    }

    array_[sizeOfstack_++] = newItem;
}



template<class T>
void stack<T>::pop() {
    if (!empty()) {
        sizeOfstack_--;
    }
}

template<class T>
T stack<T>::top() {
    if (!empty()) {
        return array_[sizeOfstack_ - 1];
    }
}



template<class T>
unsigned stack<T>::getSize() {
    return sizeOfstack_;
}



template<class T>
void stack<T>::print() {
    if (!empty()) {
        for (int i = sizeOfstack_ - 1; i > -1; i--) {
            cout << array_[i] << ' ';
        }
        cout << '\n';
    }
    else {
        cout << "stack is empty\n";
    }
}

#endif //TEST_stack_H
