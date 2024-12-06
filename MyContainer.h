#pragma once

#include <iostream>
#include "MyList.h"
#include "MyVector.h"

template<typename T>
class MyContainer{
    public:
        virtual void push_back(const T &val) = 0;
        virtual void pop_back() = 0;
        virtual int size() const = 0;
        virtual ~MyContainer() = default;

        static MyContainer<T> *Create(MyContainer<T> *type) {
            if (dynamic_cast<MyList<T> *>(type)) {
                return new MyList<T>();
            }else if (dynamic_cast<MyVector<T> *>(type)) {
                return new MyVector<T>();
            }else {
                return new MyVector<T>();
            }
        }
};
