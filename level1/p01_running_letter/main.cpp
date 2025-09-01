#include <iostream>
#include <thread>
#include <chrono>

int main() {
    std::string word = "A";
    int width = 60;
    int MaxRightW = width - (int)word.size();
    int pos = 0;
    int dir = 1;

    while (true) {
        std::cout << "\r" << std::string(width, ' ');
        std::cout << "\r" << std::string(pos, ' ') << word << std::flush;

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        pos += dir;
        if (pos >= MaxRightW) { pos = MaxRightW; dir = -1; }
        else if (pos <= 0) { pos = 0; dir = 1; }
    }
}