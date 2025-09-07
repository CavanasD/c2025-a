#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

int isPrime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
     //Rec the calculating time
    auto start = high_resolution_clock::now();
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
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "\n\n>>>>>运行时间: " << duration.count() << " μs<<<<<" << endl;

    return 0;
}
