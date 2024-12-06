#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct RuleContainer {
    vector<int> next;
    vector<int> prev;
};

void partOne();
void partTwo();

int main() {
    partTwo();

    return 0;
}

void partOne() {
    if (ifstream fs("../inputs/puzzle1.txt"); fs.is_open()) {
        int result = 0;

        map<int, RuleContainer> rules;

        string line;
        while (getline(fs, line)) {
            int separatorPos = line.find('|');

            if (separatorPos != string::npos) {
                // Read rules
                int first = stoi(line.substr(0, separatorPos));
                int second = stoi(line.substr(separatorPos + 1));

                rules[first].next.push_back(second);
                rules[second].prev.push_back(first);
            } else if (line != "") {
                // Making updates
                vector<int> update;

                stringstream ss(line);
                string item;
                while (getline(ss, item, ',')) {
                    update.push_back(stoi(item));
                }

                bool valid = true;
                for (int current = 0; current < update.size(); ++current) {
                    // Check next
                    for (int next = current + 1; next < update.size(); ++next) {
                        if (find(rules[update[current]].next.begin(), rules[update[current]].next.end(), update[next]) == rules[update[current]].next.end()) {
                            valid = false;
                        }

                        if (!valid) break;
                    }

                    if (!valid) break;
                }

                if (valid)
                    result += update[update.size() / 2];
            }
        }

        cout << result << endl;
    }
}

void partTwo() {
    if (ifstream fs("../inputs/puzzle2"
                    ".txt"); fs.is_open()) {
        int result = 0;

        map<int, RuleContainer> rules;

        string line;
        while (getline(fs, line)) {
            int separatorPos = line.find('|');

            if (separatorPos != string::npos) {
                // Read rules
                int first = stoi(line.substr(0, separatorPos));
                int second = stoi(line.substr(separatorPos + 1));

                rules[first].next.push_back(second);
                rules[second].prev.push_back(first);
            } else if (line != "") {
                // Making updates
                vector<int> update;

                stringstream ss(line);
                string item;
                while (getline(ss, item, ',')) {
                    update.push_back(stoi(item));
                }

                bool valid = true;
                for (int current = 0; current < update.size(); ++current) {
                    // Check next
                    for (int next = current + 1; next < update.size(); ++next) {
                        if (find(rules[update[current]].next.begin(), rules[update[current]].next.end(), update[next]) == rules[update[current]].next.end()) {
                            valid = false;
                        }

                        if (!valid) break;
                    }

                    if (!valid) break;
                }

                if (!valid) {
                    // Order them correctly
                    while (!valid) {
                        for (int current = 0; current < update.size(); ++current) {
                            // Check next
                            for (int next = current + 1; next < update.size(); ++next) {
                                if (find(rules[update[current]].next.begin(), rules[update[current]].next.end(), update[next]) == rules[update[current]].next.end()) {
                                    int tmp = update[next];
                                    update.erase(remove(update.begin(), update.end(), tmp), update.end());
                                    update.insert(update.begin() + current, tmp);
                                    current = 0;
                                }
                            }

                            valid = true;
                        }
                    }

                    result += update[update.size() / 2];
                }
            }
        }

        cout << result << endl;
    }
}