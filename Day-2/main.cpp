#include <iostream>
#include <fstream>
#include <sstream>
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

        string line;
        while (getline(fs, line)) {
            stringstream ss(line);
            bool isValid = true;

            vector<int> levels;
            int level;
            while (ss >> level) {
                levels.push_back(level);
            }

            if (levels[0] == levels[1]) {
                isValid = false;
            }

            bool isIncreasing = (levels[0] < levels[1]);

            for (int i = 0; i < levels.size()-1; ++i) {
                int diff = abs(levels[i] - levels[i+1]);
                if (diff >= 1 && diff <= 3) {
                    if (levels[i] < levels[i+1] != isIncreasing) {
                        isValid = false;
                    }
                } else {
                    isValid = false;
                }
            }

            if (isValid)
                ++result;
        }

        cout << result << endl;
    }
}

void partTwo() {
    if (ifstream fs("../inputs/puzzle2.txt"); fs.is_open()) {
        int result = 0;

        string line;
        while (getline(fs, line)) {
            stringstream ss(line);
            bool isValid = true;

            vector<int> levels;
            int level;
            while (ss >> level) {
                levels.push_back(level);
            }

            if (levels[0] == levels[1]) {
                isValid = false;
            }

            bool isIncreasing = (levels[0] < levels[1]);

            for (int i = 0; i < levels.size()-1; ++i) {
                int diff = abs(levels[i] - levels[i+1]);
                if (diff >= 1 && diff <= 3) {
                    if (levels[i] < levels[i+1] != isIncreasing) {
                        isValid = false;
                    }
                } else {
                    isValid = false;
                }
            }

            if (isValid)
                ++result;
            else {
                int tmp;
                for (int i = 0 ; i < levels.size(); ++i) {
                    tmp = levels[i];
                    levels.erase(levels.begin() + i);

                    isValid = true;

                    if (levels[0] == levels[1]) {
                        isValid = false;
                    }

                    bool isIncreasing = (levels[0] < levels[1]);

                    for (int i = 0; i < levels.size()-1; ++i) {
                        int diff = abs(levels[i] - levels[i+1]);
                        if (diff >= 1 && diff <= 3) {
                            if (levels[i] < levels[i+1] != isIncreasing) {
                                isValid = false;
                            }
                        } else {
                            isValid = false;
                        }
                    }

                    if (isValid) {
                        ++result;
                        break;
                    }

                    levels.emplace(levels.begin() + i, tmp);
                }
            }
        }

        cout << result << endl;
    }
}