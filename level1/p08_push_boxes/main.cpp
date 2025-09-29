#include <iostream>
#include <conio.h>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <fstream>
#include <filesystem>
#include <algorithm>

using namespace std;
namespace fs = std::filesystem;

int WIDTH = 0, HEIGHT = 0;
vector<string> maze;
int playerX, playerY;
int steps = 0;
string playerName;

// 读取地图
bool loadMap(const string &filename) {
    ifstream fin(filename);
    if (!fin.is_open()) return false;
    maze.clear();
    string line;
    while (getline(fin, line)) {
        maze.push_back(line);
    }
    fin.close();
    HEIGHT = maze.size();
    WIDTH = maze.empty() ? 0 : maze[0].size();
    return true;
}

// 找到玩家位置
void findPlayer() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (maze[y][x] == 'P') {
                playerX = x;
                playerY = y;
                return;
            }
        }
    }
}

// 绘制地图
void draw() {
    system("cls");
    for (auto &line : maze) {
        cout << line << "\n";
    }
    cout << "Player: " << playerName << "  Steps: " << steps << "\n";
}

// 判断是否胜利
bool isWin() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (maze[y][x] == '.') return false;
        }
    }
    return true;
}

// 移动逻辑
void movePlayer(int dx, int dy) {
    int nx = playerX + dx;
    int ny = playerY + dy;
    int nnx = playerX + 2 * dx;
    int nny = playerY + 2 * dy;

    char next = maze[ny][nx];
    char next2 = maze[nny][nnx];

    if (next == ' ' || next == '.') {
        // 玩家移动
        maze[playerY][playerX] = (maze[playerY][playerX] == 'P') ? ' ' : maze[playerY][playerX];
        if (maze[playerY][playerX] == '*') maze[playerY][playerX] = '.';
        playerX = nx;
        playerY = ny;
        maze[playerY][playerX] = 'P';
        steps++;
    } else if (next == 'B' || next == '*') {
        if (next2 == ' ' || next2 == '.') {
            // 推箱子
            maze[nny][nnx] = (next2 == '.') ? '*' : 'B';
            maze[ny][nx] = (next == '*') ? '.' : 'P';
            maze[playerY][playerX] = (maze[playerY][playerX] == 'P') ? ' ' : maze[playerY][playerX];
            if (maze[playerY][playerX] == '*') maze[playerY][playerX] = '.';
            playerX = nx;
            playerY = ny;
            steps++;
        }
    }
}

// 保存成绩
void saveScore(const string &mapName, int steps) {
    ofstream fout("score.txt", ios::app);
    fout << playerName << " " << mapName << " " << steps << " steps\n";
    fout.close();
}

// 列出关卡
vector<string> listMaps() {
    vector<string> maps;
    for (auto &p : fs::directory_iterator(".")) {
        if (p.is_regular_file()) {
            string fname = p.path().filename().string();
            if (fname.rfind("maze", 0) == 0 && fname.find(".txt") != string::npos) {
                maps.push_back(fname);
            }
        }
    }
    sort(maps.begin(), maps.end());
    return maps;
}

int main() {
    cout << "Enter your name: ";
    cin >> playerName;

    while (true) {
        // 列出关卡
        auto maps = listMaps();
        if (maps.empty()) {
            cout << "No map files found!\n";
            return 0;
        }

        cout << "\n=== BOX GAME Menu ===\n";
        cout << "Available levels:\n";
        for (int i = 0; i < (int)maps.size(); i++) {
            cout << i + 1 << ". " << maps[i] << "\n";
        }
        cout << "0. Quit\n";
        cout << "Choose level: ";
        int choice;
        cin >> choice;

        if (choice == 0) break;
        if (choice < 1 || choice > (int)maps.size()) {
            cout << "Invalid choice!\n";
            continue;
        }

        string mapFile = maps[choice - 1];
        if (!loadMap(mapFile)) {
            cout << "Failed to load " << mapFile << "\n";
            continue;
        }

        steps = 0;
        findPlayer();

        while (true) {
            draw();
            if (isWin()) {
                cout << "Level " << mapFile << " cleared in " << steps << " steps!\n";
                saveScore(mapFile, steps);
                system("pause");
                break;
            }

            if (_kbhit()) {
                int ch = _getch();
                if (ch == 'w') movePlayer(0, -1);
                if (ch == 's') movePlayer(0, 1);
                if (ch == 'a') movePlayer(-1, 0);
                if (ch == 'd') movePlayer(1, 0);
                if (ch == 'q') {
                    cout << "Quit Level.\n";
                    break;
                }
            }

            this_thread::sleep_for(chrono::milliseconds(60));
        }
    }

    return 0;
}
