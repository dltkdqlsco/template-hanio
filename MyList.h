#pragma once

#include <iostream>
#include "MyContainer.h"

using namespace std;

template<typename T>
class MyList : public MyContainer<T>{
    public:
        class Node{ 
          public:
            Node() : data{0}, pnode{nullptr}{}

            Node(const T &data, Node *pnode) : data{data}, pnode{pnode}{}

            public:
                T data;   
                Node *pnode; 
        };

        MyList() : head{nullptr}{}

        ~MyList(){
                Node *temp = head;

            while(temp){
                Node *next = temp->pnode;
                delete temp;
                temp = next;
            }
    
            head = nullptr;
        }

        void push_back(const T &val) override{
            if(!head){
                head = new Node(val, nullptr);
                return;
            }

            Node *temp = head;
            Node *newNode = new Node(val, nullptr);

            while(temp->pnode != nullptr){
                temp = temp->pnode;
            }

            temp->pnode = newNode;
        }

        void pop_back() override{
            if(!head){
                throw out_of_range("list is empty");
            }

            if(!head->pnode){
                delete head;
                head = nullptr; 
                return;
            }

            Node *temp = head;
            Node *pretemp = head;   
            while(temp->pnode != nullptr){
                pretemp = temp;
                temp = temp->pnode;
            }

            delete temp;
            pretemp->pnode = nullptr; 
        }

        int size() const override{
            Node *temp = head;
            int count = 0;

            while(temp){  
                temp = temp->pnode;
                ++count;
            }

            return count;
        }

        T &back(){
            if(!head){
                throw out_of_range("list is empty");
            }

            Node *temp = head;
            while(temp->pnode != nullptr){
                temp = temp->pnode;
            }
            return temp->data;
        }

        const T &back() const{
            if(!head){
                throw out_of_range("list is empty");
            }
            Node *temp = head;
            while(temp->pnode != nullptr){
                temp = temp->pnode;
            }
            return temp->data;
        }

    public:
        Node *head;  // 처음 node에 대한 포인터
};

