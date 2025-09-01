#include <iostream>
#include <thread>#include <chrono>

using namespace std;

static const int width = 70;

int main() {
    int maxwidth = width - 1;
    int position = 0;
    int dir = 1;
    while (true) {
        cout<<"\r" << string(position, ' ') << "A" << flush;
        system("cls");
        position += dir;
        if (position >= maxwidth) {
            maxwidth = position;dir = -1;
        }
        else if (position <= 0) {
            position = 0; dir = 1;
        }


    }
}