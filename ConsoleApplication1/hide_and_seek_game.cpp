#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <Windows.h>

using namespace std;

const int MAP_SIZE = 10;
const int TIME_LIMIT = 20;

void printMap(char map[MAP_SIZE][MAP_SIZE], bool revealed[MAP_SIZE][MAP_SIZE], int playerX, int playerY) {
    system("cls");  // Clear the console window
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            if (i == playerY && j == playerX) {
                cout << "R ";  // Red dot for player 2
            }
            else if (revealed[i][j]) {
                cout << map[i][j] << " ";  // Show the map if revealed
            }
            else {
                cout << "# ";  // Censored part of the map
            }
        }
        cout << endl;
    }
}

int main() {
    char map[MAP_SIZE][MAP_SIZE] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', '#', '#', '#', '#', ' ', ' ', '#'},
        {'#', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', '#'},
        {'#', ' ', '#', ' ', '#', '#', '#', '#', ' ', '#'},
        {'#', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', ' ', '#', ' ', '#', '#', '#', '#'},
        {'#', ' ', '#', ' ', '#', ' ', '#', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };

    bool revealed[MAP_SIZE][MAP_SIZE] = { 0 };
    int playerX = 0, playerY = 0;  // Player 1's starting position
    int secondsLeft = TIME_LIMIT;

    cout << "Player 1, choose a spot to hide (enter X and Y coordinates): ";
    cin >> playerX >> playerY;
    map[playerY][playerX] = 'B';  // Blue dot for player 1
    revealed[playerY][playerX] = true;
    printMap(map, revealed, -1, -1);  // Show the whole map for player 2 at the beginning

    cout << "Press any key to start the game!" << endl;
    _getch();  // Wait for player 2 to start the game

    while (secondsLeft > 0) {
        printMap(map, revealed, playerX, playerY);
        cout << "Time left: " << secondsLeft << endl;
        cout << "Player 2, use arrow keys to move. Press Q to quit." << endl;
        if (_kbhit()) {
            char key = _getch();
            if (key == 'q' || key == 'Q') {
                cout << "You gave up! Player 1 wins!" << endl;
                    return 0;
            }
            else if (key == 72 && playerY > 0 && map[playerY - 1][playerX] != '#') {
                // Up arrow
                playerY--;
                if (map[playerY][playerX] == 'B') {
                    cout << "Congratulations! You found the hidden spot! Player 2 wins!" << endl;
                    return 0;
                }
                revealed[playerY][playerX] = true;
            }
            else if (key == 80 && playerY < MAP_SIZE - 1 && map[playerY + 1][playerX] != '#') {
                // Down arrow
                playerY++;
                if (map[playerY][playerX] == 'B') {
                    cout << "Congratulations! You found the hidden spot! Player 2 wins!" << endl;
                    return 0;
                }
                revealed[playerY][playerX] = true;
            }
            else if (key == 75 && playerX > 0 && map[playerY][playerX - 1] != '#') {
                // Left arrow
                playerX--;
                if (map[playerY][playerX] == 'B') {
                    cout << "Congratulations! You found the hidden spot! Player 2 wins!" << endl;
                    return 0;
                }
                revealed[playerY][playerX] = true;
            }
            else if (key == 77 && playerX < MAP_SIZE - 1 && map[playerY][playerX + 1] != '#') {
                // Right arrow
                playerX++;
                if (map[playerY][playerX] == 'B') {
                    cout << "Congratulations! You found the hidden spot! Player 2 wins!" << endl;
                    return 0;
                }
                revealed[playerY][playerX] = true;
            }
        }
        this_thread::sleep_for(chrono::milliseconds(1000));  // Wait for 1 second
        secondsLeft--;
    }
    cout << "Time's up! Player 1 wins!" << endl;
    return 0;
}