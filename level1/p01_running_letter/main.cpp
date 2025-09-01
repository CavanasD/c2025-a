#include <iostream>
#include <thread>
#include <chrono>

int main() {
    std::string word = "A";
    int width = 80;
    int pos = 0;
    int dir = 1;
    int right = width - (int)word.size();

    while (true) {
        std::cout << "\r";               // 回到行首
        std::cout << std::string(pos, ' ') << word << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(60));
        pos += dir;
        if (pos >= right) { pos = right; dir = -1; }
        else if (pos <= 0) { pos = 0; dir = 1; }
    }
}