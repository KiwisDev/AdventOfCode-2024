#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void partOne();
void partTwo();

int main() {
    partTwo();

    return 0;
}

void partOne() {
    if (ifstream fs("../inputs/puzzle1.txt"); fs.is_open()) {
        int result = 0;

        vector<vector<char>> input;

        string line;
        while (getline(fs, line)) {
            vector<char> row;
            for (int i = 0; i < line.length(); ++i) {
                row.push_back(line[i]);
            }
            input.push_back(row);
        }

        for (int y = 0; y < input.size(); ++y) {
            for (int x = 0; x < input[y].size(); ++x) {
                if (input[y][x] == 'X') {
                    // Horizontal right
                    if (x + 1 < input[y].size() && input[y][x+1] == 'M') {
                        if (x + 2 < input[y].size() && input[y][x+2] == 'A') {
                            if (x + 3 < input[y].size() && input[y][x+3] == 'S') {
                                ++result;
                            }
                        }
                    }

                    // Horizontal left
                    if (x - 1 >= 0 && input[y][x-1] == 'M') {
                        if (x - 2 >= 0 && input[y][x-2] == 'A') {
                            if (x - 3 >= 0 && input[y][x-3] == 'S') {
                                ++result;
                            }
                        }
                    }

                    // Vertical up
                    if (y - 1 >= 0 && input[y-1][x] == 'M') {
                        if (y - 2 >= 0 && input[y-2][x] == 'A') {
                            if (y - 3 >= 0 && input[y-3][x] == 'S') {
                                ++result;
                            }
                        }
                    }

                    // Vertical down
                    if (y + 1 < input.size() && input[y+1][x] == 'M') {
                        if (y + 2 < input.size() && input[y+2][x] == 'A') {
                            if (y + 3 < input.size() && input[y+3][x] == 'S') {
                                ++result;
                            }
                        }
                    }

                    // Diagonal up right
                    if (y - 1 >= 0 && x + 1 < input[y].size() && input[y-1][x+1] == 'M') {
                        if (y - 2 >= 0 && x + 2 < input[y].size() && input[y-2][x+2] == 'A') {
                            if (y - 3 >= 0 && x + 3 < input[y].size() && input[y-3][x+3] == 'S') {
                                ++result;
                            }
                        }
                    }

                    // Diagonal up left
                    if (y - 1 >= 0 && x - 1 >= 0 && input[y-1][x-1] == 'M') {
                        if (y - 2 >= 0 && x - 2 >= 0 && input[y-2][x-2] == 'A') {
                            if (y - 3 >= 0 && x - 3 >= 0 && input[y-3][x-3] == 'S') {
                                ++result;
                            }
                        }
                    }

                    // Diagonal down right
                    if (y + 1 < input.size() && x + 1 < input[y].size() && input[y+1][x+1] == 'M') {
                        if (y + 2 < input.size() && x + 2 < input[y].size() && input[y+2][x+2] == 'A') {
                            if (y + 3 < input.size() && x + 3 < input[y].size() && input[y+3][x+3] == 'S') {
                                ++result;
                            }
                        }
                    }

                    // Diagonal down left
                    if (y + 1 < input.size() && x - 1 >= 0 && input[y+1][x-1] == 'M') {
                        if (y + 2 < input.size() && x - 2 >= 0 && input[y+2][x-2] == 'A') {
                            if (y + 3 < input.size() && x - 3 >= 0 && input[y+3][x-3] == 'S') {
                                ++result;
                            }
                        }
                    }
                }
            }
        }

        cout << result << endl;
    }
}

void partTwo() {
if (ifstream fs("../inputs/puzzle2.txt"); fs.is_open()) {
        int result = 0;

        vector<vector<char>> input;

        string line;
        while (getline(fs, line)) {
            vector<char> row;
            for (int i = 0; i < line.length(); ++i) {
                row.push_back(line[i]);
            }
            input.push_back(row);
        }

        for (int y = 0; y < input.size(); ++y) {
            for (int x = 0; x < input[y].size(); ++x) {
                if (input[y][x] == 'A') {
                    // Diagonal up left to down right
                    if (((y - 1 >= 0 && x - 1 >= 0 && input[y-1][x-1] == 'M') && (y + 1 < input.size() && x + 1 < input[y].size() && input[y+1][x+1] == 'S')) || ((y - 1 >= 0 && x - 1 >= 0 && input[y-1][x-1] == 'S') && (y + 1 < input.size() && x + 1 < input[y].size() && input[y+1][x+1] == 'M'))) {
                        // Diagonal up right to down left
                        if (((y - 1 >= 0 && x + 1 < input[y].size() && input[y-1][x+1] == 'M') && (y + 1 < input.size() && x - 1 >= 0 && input[y+1][x-1] == 'S')) || ((y - 1 >= 0 && x + 1 < input[y].size() && input[y-1][x+1] == 'S') && (y + 1 < input.size() && x - 1 >= 0 && input[y+1][x-1] == 'M'))) {
                            ++result;
                        }
                    }
                }
            }
        }

        cout << result << endl;
    }
}