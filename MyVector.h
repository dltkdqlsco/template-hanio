#pragma once
#include <iostream>
#include "MyContainer.h"

using namespace std;

template<typename T>
class MyVector : public MyContainer<T>{
    public:
        MyVector() : canSaveNum{1}, pCanSaveNum{new T[canSaveNum]}, currentNum{0}{}

        ~MyVector(){
            delete[] pCanSaveNum;
        }

        void push_back(const T& val) override{
            if(canSaveNum == currentNum){
            T *new_array = new T[canSaveNum * 2];
            memcpy(new_array, pCanSaveNum, sizeof(T) * canSaveNum);
            delete[] pCanSaveNum;

            pCanSaveNum = new_array;

            canSaveNum *= 2;
            }

            pCanSaveNum[currentNum++] = val;
        }

        void pop_back() override{
            if(currentNum == 0){
                cout << "not have num in the any index" << endl;
            }else{
                --currentNum;
            }
        }

        int size() const override{
            return currentNum;
        }

        T &operator[](const int index){
            return pCanSaveNum[index];
        }

        const T &operator[](const int index) const{
            return pCanSaveNum[index];
        }
        
    private:
        int canSaveNum;
        T *pCanSaveNum;
        int currentNum;
};
