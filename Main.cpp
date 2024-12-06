#include <iostream>

#include "MyContainer.h"
#include "MyVector.h"
#include "MyList.h"
#include "MyStack.h"

using namespace std;
using TYPE = MyStack<int, MyContainer<int>>;
// 디스크 이동 함수
void moveDisk(TYPE& from, TYPE& to, int fromName, int toName) {
    if (!from.empty() && (to.empty() || from.top() < to.top())) {
        cout << "Move disk " << from.top() << " from " << fromName << " to " << toName << endl;
        to.push(from.top());
        from.pop();
    } else if (!to.empty() && (from.empty() || to.top() < from.top())) {
        cout << "Move disk " << to.top() << " from " << toName << " to " << fromName << endl;
        from.push(to.top());
        to.pop();
    }
}

// 반복적 하노이 함수
void hanoiIterative(int n, TYPE& source, TYPE& auxiliary, TYPE& destination) {
    int names[] = {1, 2, 3};
    if (n % 2 == 0) swap(names[1], names[2]); // 짝수라면 보조와 목적지를 교환

    int totalMoves = (1 << n) - 1; // 총 이동 횟수: 2^n - 1
    for (int i = 1; i <= totalMoves; ++i) {
        if (i % 3 == 1) {
            moveDisk(source, destination, names[0], names[2]);
        } else if (i % 3 == 2) {
            moveDisk(source, auxiliary, names[0], names[1]);
        } else if (i % 3 == 0) {
            moveDisk(auxiliary, destination, names[1], names[2]);
        }
    }
}

int main() {
    string containerType;
    int numDisks;

    cin >> containerType;
    cin >> numDisks;

    if (containerType == "vector") {
        MyStack<int, MyVector<int>> source, auxiliary, destination;

        // 첫 번째 스택에 디스크 추가
        for (int i = numDisks; i >= 1; --i) {
            source.push(i);
        }

        // 반복적 하노이 실행
        hanoiIterative(numDisks, source, auxiliary, destination);

        cout << "Hanoi completed using vector!" << endl;
    } else if (containerType == "list") {
        MyStack<int, MyList<int>> source, auxiliary, destination;

        // 첫 번째 스택에 디스크 추가
        for (int i = numDisks; i >= 1; --i) {
            source.push(i);
        }

        // 반복적 하노이 실행
        hanoiIterative(numDisks, source, auxiliary, destination);

        cout << "Hanoi completed using list!" << endl;
    } else {
        cerr << "Invalid container type!" << endl;
    }

    return 0;
}
