#include <algorithm>
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
        vector<int> listLeft;
        vector<int> listRight;

        int result = 0;

        // Read file and put the location id on the corresponding list
        int index = 0;
        string word;
        while (fs >> word) {
            (index % 2 == 0) ? listLeft.push_back(stoi(word)) : listRight.push_back(stoi(word));
            ++index;
        }

        // Sort the list
        sort(listLeft.begin(), listLeft.end());
        sort(listRight.begin(), listRight.end());

        // Add all the differences
        for (int i = 0; i < listLeft.size(); ++i) {
            result += abs(listLeft[i] - listRight[i]);
        }

        cout << result << endl;
    }
}

void partTwo() {
    if (ifstream fs("../inputs/puzzle2.txt"); fs.is_open()) {
        vector<int> listLeft;
        vector<int> listRight;

        int result = 0;

        // Read file and put the location id on the corresponding list
        int index = 0;
        string word;
        while (fs >> word) {
            (index % 2 == 0) ? listLeft.push_back(stoi(word)) : listRight.push_back(stoi(word));
            ++index;
        }

        // Sort the list
        sort(listLeft.begin(), listLeft.end());
        sort(listRight.begin(), listRight.end());

        // Add all the differences
        for (int i = 0; i < listLeft.size(); ++i) {
            result += count(listRight.begin(), listRight.end(), listLeft[i]) * listLeft[i];
        }

        cout << result << endl;
    }
}