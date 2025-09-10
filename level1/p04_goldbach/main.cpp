#include <iostream>
using namespace std;

// 判断是否为质数
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    // 验证4到100的所有偶数
    for (int n = 4; n <= 100; n += 2) {
        bool found = false;
        // 寻找两个质数的和等于n
        for (int i = 2; i <= n/2; i++) {
            if (isPrime(i) && isPrime(n - i)) {
                cout << n << " = " << i << " + " << (n - i) << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Wrong！" << n << "It can't be divided!" << endl;
        }
    }
    cout << "Success" << endl;
    return 0;
}