#include <iostream>
#include <conio.h>
#include <thread>
#include <chrono>

using namespace std;

const int MAZE_WIDTH  = 40;
const int MAZE_HEIGHT = 20;

// 每行长度严格为 40
char mazeMap[MAZE_HEIGHT][MAZE_WIDTH + 1] = {
    "########################################",
    "#     #   #   ###     #     #    #    E#",
    "### ### ##### ### ### ### ##### ### ####",
    "#   #   #       # ###   #     #   #    #",
    "# ### ### # ### # ### ##### ### # #### #",
    "# #   #   #   # #   #     #   # # #    #",
    "# # ### ##### # ##### ### # ### # #### #",
    "# #     #     #     #   # #   # #    # #",
    "# ####### ###### #### ### ### # #### # #",
    "#       #     #       #     # #    #   #",
    "## #### ##### # ## ## ##### # ###### ###",
    "#     #     # #     #     #   #       ##",
    "# ### ##### # ##### ### ### ### ### # ##",
    "# #   #   # #     #   #   #     #   # ##",
    "# # ### # # ##### ### # ####### ### # ##",
    "# #     # #     #   # #       #   #   ##",
    "# ####### ####### # ### ##### # ########",
    "#         #     # #     #   # #        #",
    "######### ####### ####### # # ##########",
    "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"
};

int playerPosX = 1, playerPosY = 1;
int exitX = 38, exitY = 1;

void drawMazeMap() {
    //cls to animation
    system("cls");
    for (int y = 0; y < MAZE_HEIGHT; ++y) {
        for (int x = 0; x < MAZE_WIDTH; ++x) {
            if (x == playerPosX && y == playerPosY) {
                cout << 'P';
            } else {
                cout << mazeMap[y][x];
            }
        }
        cout << '\n';
    }
}

bool canMoveTo(int x, int y) {
    if (x < 0 || x >= MAZE_WIDTH || y < 0 || y >= MAZE_HEIGHT) return false;
    char c = mazeMap[y][x];
    return c != '#';
}

void handleInput() {
    if (!_kbhit()) return;
    int ch = _getch();
    if (ch == 0 || ch == 224) {
        // special key (arrow keys)
        int code = _getch();
        switch (code) {
            case 72: // up
                if (canMoveTo(playerPosX, playerPosY - 1)) --playerPosY;
                break;
            case 80: // down
                if (canMoveTo(playerPosX, playerPosY + 1)) ++playerPosY;
                break;
            case 75: // left
                if (canMoveTo(playerPosX - 1, playerPosY)) --playerPosX;
                break;
            case 77: // right
                if (canMoveTo(playerPosX + 1, playerPosY)) ++playerPosX;
                break;
        }
    } else {
        // normal key (WASD, q)
        char c = static_cast<char>(ch);
        if (c == 'w' || c == 'W') {
            if (canMoveTo(playerPosX, playerPosY - 1)) --playerPosY;
        } else if (c == 's' || c == 'S') {
            if (canMoveTo(playerPosX, playerPosY + 1)) ++playerPosY;
        } else if (c == 'a' || c == 'A') {
            if (canMoveTo(playerPosX - 1, playerPosY)) --playerPosX;
        } else if (c == 'd' || c == 'D') {
            if (canMoveTo(playerPosX + 1, playerPosY)) ++playerPosX;
        } else if (c == 'q' || c == 'Q') {
            cout << "\nQuited\n";
            exit(0);
        }
    }
}

int main() {
    // 确保起始点不是墙
    if (!canMoveTo(playerPosX, playerPosY)) {
        cerr << "WARNING: INVALID INITIAL POSITION!\n";
        return 1;
    }

    while (true) {
        drawMazeMap();
        //胜利
        if (playerPosX == exitX && playerPosY == exitY) {
            cout << "\nYOU WIN\n";
            break;
        }
        handleInput();
        std::this_thread::sleep_for(std::chrono::milliseconds(60));
    }

    return 0;
}
