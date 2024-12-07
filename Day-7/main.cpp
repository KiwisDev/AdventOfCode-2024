#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void partOne();
void partTwo();

void calculateCombinationsPartOne(const vector<long long>& nums, int index, long long currentValue, vector<long long>& results);
void calculateCombinationsPartTwo(const vector<long long>& nums, int index, long long currentValue, vector<long long>& results);

int main() {
    partTwo();

    return 0;
}

void partOne() {
    long long result = 0;
    ifstream fs("../inputs/puzzle1.txt");

    string line;
    while (getline(fs, line)) {
        vector<long long> numbers;
        vector<long long> results;

        int colonPos = line.find(':');
        long long eqResult = stoll(line.substr(0, colonPos));

        stringstream ss(line.substr(colonPos + 1));
        long long number;
        while (ss >> number) numbers.push_back(number);

        calculateCombinationsPartOne(numbers, 1, numbers[0], results);

        for (int i = 0; i < results.size(); ++i) {
            if (results[i] == eqResult) {
                result += eqResult;
                break;
            }
        }
    }

    cout << result << endl;
}

void partTwo() {
    long long result = 0;
    ifstream fs("../inputs/puzzle2.txt");

    string line;
    while (getline(fs, line)) {
        vector<long long> numbers;
        vector<long long> results;

        int colonPos = line.find(':');
        long long eqResult = stoll(line.substr(0, colonPos));

        stringstream ss(line.substr(colonPos + 1));
        long long number;
        while (ss >> number) numbers.push_back(number);

        calculateCombinationsPartTwo(numbers, 1, numbers[0], results);

        for (int i = 0; i < results.size(); ++i) {
            if (results[i] == eqResult) {
                result += eqResult;
                break;
            }
        }
    }

    cout << result << endl;
}

void calculateCombinationsPartOne(const vector<long long> &nums, int index, long long currentValue, vector<long long> &results) {
    if (index == nums.size()) {
        results.push_back(currentValue);
        return;
    }

    calculateCombinationsPartOne(nums, index + 1, currentValue + nums[index], results);
    calculateCombinationsPartOne(nums, index + 1, currentValue * nums[index], results);
}

void calculateCombinationsPartTwo(const vector<long long> &nums, int index, long long currentValue, vector<long long> &results) {
    if (index == nums.size()) {
        results.push_back(currentValue);
        return;
    }

    calculateCombinationsPartTwo(nums, index + 1, currentValue + nums[index], results);
    calculateCombinationsPartTwo(nums, index + 1, currentValue * nums[index], results);
    calculateCombinationsPartTwo(nums, index + 1, stoll(to_string(currentValue) + to_string(nums[index])), results);
}