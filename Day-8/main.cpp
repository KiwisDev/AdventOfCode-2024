#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void partOne();
void partTwo();

struct Pos {
    friend bool operator==(const Pos &Pos1, const Pos &Pos2) {
        return Pos1.x == Pos2.x && Pos1.y == Pos2.y;
    }

    int x;
    int y;
};

int main() {
    partTwo();

    return 0;
}

void partOne() {
    if (ifstream fs("../inputs/puzzle1.txt"); fs.is_open()) {
        map<char, vector<Pos>> antennas;
        vector<Pos> antinodes;

        string line;
        int yIndex = 0;
        while (getline(fs, line)) {
            for (int x = 0; x < line.size(); ++x) {
                if (line[x] != '.') {
                    antennas[line[x]].push_back(Pos{x, yIndex});
                }
            }
            ++yIndex;
        }

        Pos gridSize = Pos{(int)line.size(), yIndex};

        for (auto it = antennas.begin(); it != antennas.end(); ++it) {
            vector<Pos>& positions = it->second;
            for (int i = 0; i < positions.size() - 1; ++i) {
                for (int j = i + 1; j < positions.size(); ++j) {
                    int xDelta = positions[i].x - positions[j].x;
                    int yDelta = positions[i].y - positions[j].y;

                    Pos newPosI = Pos{positions[i].x + xDelta, positions[i].y + yDelta};
                    if (newPosI.x >= 0 && newPosI.x < gridSize.x && newPosI.y >= 0 && newPosI.y < gridSize.y && find(antinodes.begin(), antinodes.end(), newPosI) == antinodes.end())
                        antinodes.push_back(newPosI);

                    Pos newPosJ = Pos{positions[j].x - xDelta, positions[j].y - yDelta};
                    if (newPosJ.x >= 0 && newPosJ.x < gridSize.x && newPosJ.y >= 0 && newPosJ.y < gridSize.y && find(antinodes.begin(), antinodes.end(), newPosJ) == antinodes.end())
                        antinodes.push_back(newPosJ);
                }
            }
        }

        cout << antinodes.size() << endl;
    }
}

void partTwo() {
    if (ifstream fs("../inputs/puzzle2.txt"); fs.is_open()) {
        map<char, vector<Pos>> antennas;
        vector<Pos> antinodes;

        string line;
        int yIndex = 0;
        while (getline(fs, line)) {
            for (int x = 0; x < line.size(); ++x) {
                if (line[x] != '.') {
                    antennas[line[x]].push_back(Pos{x, yIndex});
                }
            }
            ++yIndex;
        }

        Pos gridSize = Pos{(int)line.size(), yIndex};

        for (auto it = antennas.begin(); it != antennas.end(); ++it) {
            vector<Pos>& positions = it->second;
            for (int i = 0; i < positions.size() - 1; ++i) {
                for (int j = i + 1; j < positions.size(); ++j) {
                    int xDelta = positions[i].x - positions[j].x;
                    int yDelta = positions[i].y - positions[j].y;

                    if (find(antinodes.begin(), antinodes.end(), positions[i]) == antinodes.end()) {
                        antinodes.push_back(positions[i]);
                    }

                    if (find(antinodes.begin(), antinodes.end(), positions[j]) == antinodes.end()) {
                        antinodes.push_back(positions[j]);
                    }

                    Pos newPosI = Pos{positions[i].x + xDelta, positions[i].y + yDelta};
                    while (newPosI.x >= 0 && newPosI.x < gridSize.x && newPosI.y >= 0 && newPosI.y < gridSize.y) {
                        if (find(antinodes.begin(), antinodes.end(), newPosI) == antinodes.end()) {
                            antinodes.push_back(newPosI);
                        }
                        newPosI = Pos{newPosI.x + xDelta, newPosI.y + yDelta};
                    }

                    Pos newPosJ = Pos{positions[j].x - xDelta, positions[j].y - yDelta};
                    while (newPosJ.x >= 0 && newPosJ.x < gridSize.x && newPosJ.y >= 0 && newPosJ.y < gridSize.y) {
                        if (find(antinodes.begin(), antinodes.end(), newPosJ) == antinodes.end()) {
                            antinodes.push_back(newPosJ);
                        }
                        newPosJ = Pos{newPosJ.x - xDelta, newPosJ.y - yDelta};
                    }
                }
            }
        }

        cout << antinodes.size() << endl;
    }
}