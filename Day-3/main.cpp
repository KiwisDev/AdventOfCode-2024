#include <iostream>
#include <fstream>
#include <string>
#include <regex>

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

        string sequence;
        string line;
        while (getline(fs, line)) {
            sequence += line ;
        }

        regex regex(R"(mul\((\d{1,3}),(\d{1,3})\))");
        sregex_iterator it_start(sequence.begin(), sequence.end(), regex);
        sregex_iterator it_end;

        for (sregex_iterator it = it_start; it != it_end; ++it) {
            const smatch& match = *it;

            int X = stoi(match[1].str());
            int Y = stoi(match[2].str());

            result += X * Y;
        }

        cout << result << endl;
    }
}

void partTwo() {
    if (ifstream fs("../inputs/puzzle2.txt"); fs.is_open()) {
        int result = 0;

        string sequence;
        string line;
        while (getline(fs, line)) {
            sequence += line ;
        }

        bool isEnable = true;

        regex regex(R"(mul\((\d{1,3}),(\d{1,3})\)|do\(\)|don't\(\))");
        sregex_iterator it_start(sequence.begin(), sequence.end(), regex);
        sregex_iterator it_end;

        for (sregex_iterator it = it_start; it != it_end; ++it) {
            const smatch& match = *it;
            cout << match[0] << endl;

            if (match[0] == "do()")
                isEnable = true;
            else if (match[0] == "don't()")
                isEnable = false;
            else if (isEnable) {
                int X = stoi(match[1].str());
                int Y = stoi(match[2].str());

                result += X * Y;
            }
        }

        cout << result << endl;
    }
}