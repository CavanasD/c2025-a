#include <iostream>

using namespace std;

int main() {
    long long k;
    cout << "Enter an integer: ";
    cin >> k;
    for (int i = 2 ; i <= k; i++) {
        if (k % i == 0) {
            cout << k << "tmd不是素数" << endl;
            return 1;

        }
        cout << k << " isPrime" << endl;
        return 0;

    }

}