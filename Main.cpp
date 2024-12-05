#include <iostream>

#include "MyContainer.h"
#include "MyVector.h"
#include "MyList.h"
#include "MyStack.h"

using namespace std;

void hanio(int n, )

int main() {
    string type;
    int num;

    getline(cin, type);
    cin >> num;

    if(type == "list"){
        MyStack<int, MyList<int>> s1, s2, s3;
    }else{
        MyStack<int, MyVector<int>> s1, s2, s3;
    }



}
