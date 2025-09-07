#include <iostream>
#include <chrono>
using namespace std;

int isPrime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
     //Print the calculate time


    int count = 0;
    for (int i = 2; i <= 1000; i++) {
        if (isPrime(i) == 1 ) {
            cout << i << " ";
            count++;
            if (count % 10 == 0) {
                cout << endl;
            }
        }
    }
    return 0;
}
