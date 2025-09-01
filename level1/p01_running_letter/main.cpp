#include <iostream>
#include <chrono>

using namespace std;

const int WIDTH = 70;

int main() {
    int MaxWidth = WIDTH - 1;
    int position = 0;
    int direction = 1;
    while (true) {
        cout << string(position, ' ') << "A" ;
        system("cls");
        position += direction;
        if (position >= MaxWidth) {
            MaxWidth = position;direction = -1;
        }
        else if (position <= 0) {
            position = 0; direction = 1;
        }
    }
}