#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define EMPTY (-1)

using namespace std;

void partOne();
void partTwo();

int readChar(char c);

int main() {
    partOne();

    return 0;
}

void partOne() {
    if (ifstream fs("../inputs/puzzle1.txt"); fs.is_open()) {
        long long result = 0;

        vector<int> disk;

        string line;
        getline(fs, line);

        // Read input
        for (int i = 0; i < line.size(); ++i) {
            if (i % 2 == 0) for (int j = 0; j < readChar(line[i]); ++j) disk.push_back(i/2);
            else for (int j = 0; j < readChar(line[i]); ++j) disk.push_back(EMPTY);
        }

        // Order disk
        bool bIsOrdered = false;
        while (!bIsOrdered) {
            int iBlock = disk.size() - 1;
            int iFree = 0;

            // Find rightmost block
            for (; iBlock >= 0; --iBlock) if (disk[iBlock] != EMPTY) break;

            // Find leftmost free
            for (; iFree < iBlock; ++iFree) if (disk[iFree] == EMPTY) break;

            // Swap block and free
            disk[iFree] = disk[iBlock];
            disk[iBlock] = EMPTY;

            // Check ordered
            bool bFoundEmpty = false;
            for (int i = 0; i < disk.size(); ++i) {
                if (disk[i] == EMPTY) {
                    bFoundEmpty = true;
                } else if (bFoundEmpty) {
                    bFoundEmpty = false;
                    break;
                }
            }
            if (bFoundEmpty) bIsOrdered = true;
        }

        // Checksum
        for (int i = 0; i < disk.size(); ++i) {
            if (disk[i] != EMPTY) result += i * disk[i];
            else break;
        }

        cout << result << endl;
    }
}

void partTwo() {
    if (ifstream fs("../inputs/puzzle1.txt"); fs.is_open()) {
        long long result = 0;

        vector<int> disk;

        string line;
        getline(fs, line);

        // Read input
        for (int i = 0; i < line.size(); ++i) {
            if (i % 2 == 0) for (int j = 0; j < readChar(line[i]); ++j) disk.push_back(i/2);
            else for (int j = 0; j < readChar(line[i]); ++j) disk.push_back(EMPTY);
        }

        // Order disk
        bool bIsOrdered = false;
        while (!bIsOrdered) {
            int iBlock = disk.size() - 1;
            int iFree = 0;

            // Find rightmost block
            for (; iBlock >= 0; --iBlock) if (disk[iBlock] != EMPTY) break;

            // Find leftmost free
            for (; iFree < iBlock; ++iFree) if (disk[iFree] == EMPTY) break;

            // Swap block and free
            disk[iFree] = disk[iBlock];
            disk[iBlock] = EMPTY;

            // Check ordered
            bool bFoundEmpty = false;
            for (int i = 0; i < disk.size(); ++i) {
                if (disk[i] == EMPTY) {
                    bFoundEmpty = true;
                } else if (bFoundEmpty) {
                    bFoundEmpty = false;
                    break;
                }
            }
            if (bFoundEmpty) bIsOrdered = true;
        }

        // Checksum
        for (int i = 0; i < disk.size(); ++i) {
            if (disk[i] != EMPTY) result += i * disk[i];
            else break;
        }

        cout << result << endl;
    }
}

int readChar(char c) {
    return c - '0';
}