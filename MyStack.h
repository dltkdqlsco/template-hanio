#pragma once
#include <iostream>

#include "MyContainer.h"

using namespace std;

template<typename T, typename C>
class MyStack : public MyContainer<T>{

    private:
        //C *container;
        MyContainer<T> *container;
    public:
        MyStack(){
           //container = new C();
           container = MyContainer<T>::Create(new C());
        }
        
        ~MyStack(){
            delete container;
        }

        bool empty() const{
            return container->size() == 0;
        }

        void push_back(const T &val) override{
            container->push_back(val);
        }

        void pop_back() override{
            if(!empty()){
                container->pop_back();
            }else{
                cerr << "stack is empty";
            }
        }

        const T &top() const{
            if(!empty()){
                return (*container)[container->size() - 1];
            }else{
                throw out_of_range("stack is empty");
            }
        }
};

template<typename T>
class MyStack<T, MyList<T>>{
    private:
        //MyList<T> *container;
        MyContainer<T> *container;
    public:
        MyStack(){
            //container = new MyList<T>();
            container = MyContainer<T>::Create(new MyList<T>());
        }
        
        ~MyStack(){
            delete container;
        }

        bool empty() const{
            return container->size() == 0;
        }

        void push_back(const T &val){
            container->push_back(val);
        }

        void pop_back(){
            if(!empty()){
                container->pop_back();
            }else{
                cerr << "stack is empty";
            }
        }

        const T &top() const{
            if(!empty()){
                return container->back();
            }else{
                throw out_of_range("stack is empty");
            }
        }
};