#include<iostream>

using namespace std;

void stepHanoi(int n, char A, char C, char B) {
    if (1 == n){
        cout << A << " -> " << C << endl;
    }else {
        stepHanoi(n-1, A, B, C);
        cout << A << " -> " << C << endl;
        stepHanoi(n-1, C, A, B);
    }
}
int main() {
    int n = 0;
    cin >> n;
    stepHanoi(n, 'A', 'C', 'B');
    return 0;
}
/*
stepHanoi(3, A, C, B)
│
├─ stepHanoi(2, A, B, C)
│   ├─ stepHanoi(1, A, C, B)  => A -> C
│   ├─ Move disk: A -> B
│   └─ stepHanoi(1, C, B, A)  => C -> B
│
├─ Move disk: A -> C
│
└─ stepHanoi(2, B, C, A)
    ├─ stepHanoi(1, B, A, C)  => B -> A
    ├─ Move disk: B -> C
    └─ stepHanoi(1, A, C, B)  => A -> C
    */