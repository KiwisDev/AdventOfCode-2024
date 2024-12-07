#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef enum {
    NORTH,
    EAST,
    SOUTH,
    WEST
} Direction;

struct Pos {
    friend bool operator==(const Pos &Pos1, const Pos &Pos2) {
        return (Pos1.x == Pos2.x && Pos1.y == Pos2.y);
    }

    int x;
    int y;
};

typedef struct GuardPos {
    friend bool operator==(const GuardPos &GuardPos1, const GuardPos &GuardPos2) {
        return (GuardPos1.x == GuardPos2.x && GuardPos1.y == GuardPos2.y && GuardPos1.direction == GuardPos2.direction);
    }

    int x;
    int y;
    Direction direction;
} GuardPos;

void partOne();
void partTwo();

int main() {
    partTwo();

    return 0;
}

void partOne() {
    if (ifstream fs("../inputs/puzzle1.txt"); fs.is_open()) {
        vector<Pos> positions;
        GuardPos guard;
        Pos gridSize;

        vector<Pos> guardPath;

        string line;
        int y = 0;
        while (getline(fs, line)) {
            gridSize.x = line.size();
            for (int x = 0; x < line.size(); ++x) {
                if (line[x] == '#') positions.push_back(Pos{x, y});
                if (line[x] == '^') {
                    guard = GuardPos{x, y, NORTH};
                    guardPath.push_back(Pos{x, y});
                }
            }
            ++y;
        }
        gridSize.y = y;

        bool isOut = false;
        while (!isOut) {
            switch (guard.direction) {
                case NORTH : {
                    int yMax = -1;
                    for (int i = 0; i < positions.size(); ++i) {
                        if (positions[i].x == guard.x && positions[i].y > yMax && positions[i].y < guard.y) yMax = positions[i].y;
                    }

                    if (yMax != -1) {
                        for (int yI = guard.y - 1; yI > yMax; --yI) {
                            if (find(guardPath.begin(), guardPath.end(), Pos{guard.x, yI}) == guardPath.end()) {
                                guardPath.push_back(Pos{guard.x, yI});
                            }
                        }

                        guard.y = yMax + 1;
                        guard.direction = EAST;
                    } else {
                        for (int yI = guard.y - 1; yI >= 0; --yI) {
                            if (find(guardPath.begin(), guardPath.end(), Pos{guard.x, yI}) == guardPath.end()) {
                                guardPath.push_back(Pos{guard.x, yI});
                            }
                        }
                        isOut = true;
                    }

                    break;
                }

                case EAST : {
                    int xMin = gridSize.x + 1;
                    for (int i = 0; i < positions.size(); ++i) {
                        if (positions[i].y == guard.y && positions[i].x < xMin && positions[i].x > guard.x) xMin = positions[i].x;
                    }

                    if (xMin != gridSize.x + 1) {
                        for (int xI = guard.x + 1; xI < xMin; ++xI) {
                            if (find(guardPath.begin(), guardPath.end(), Pos{xI, guard.y}) == guardPath.end()) {
                                guardPath.push_back(Pos{xI, guard.y});
                            }
                        }

                        guard.x = xMin - 1;
                        guard.direction = SOUTH;
                    } else {
                        for (int xI = guard.x + 1; xI < gridSize.x; ++xI) {
                            if (find(guardPath.begin(), guardPath.end(), Pos{xI, guard.y}) == guardPath.end()) {
                                guardPath.push_back(Pos{xI, guard.y});
                            }
                        }
                        isOut = true;
                    }

                    break;
                }

                case SOUTH : {
                    int yMin = gridSize.y + 1;
                    for (int i = 0; i < positions.size(); ++i) {
                        if (positions[i].x == guard.x && positions[i].y < yMin && positions[i].y > guard.y) yMin = positions[i].y;
                    }

                    if (yMin != gridSize.y + 1) {
                        for (int yI = guard.y + 1; yI < yMin; ++yI) {
                            if (find(guardPath.begin(), guardPath.end(), Pos{guard.x, yI}) == guardPath.end()) {
                                guardPath.push_back(Pos{guard.x, yI});
                            }
                        }

                        guard.y = yMin - 1;
                        guard.direction = WEST;
                    } else {
                        for (int yI = guard.y + 1; yI < gridSize.y; ++yI) {
                            if (find(guardPath.begin(), guardPath.end(), Pos{guard.x, yI}) == guardPath.end()) {
                                guardPath.push_back(Pos{guard.x, yI});
                            }
                        }
                        isOut = true;
                    }

                    break;
                }

                case WEST : {
                    int xMax = -1;
                    for (int i = 0; i < positions.size(); ++i) {
                        if (positions[i].y == guard.y && positions[i].x > xMax && positions[i].x < guard.x) xMax = positions[i].x;
                    }

                    if (xMax != -1) {
                        for (int xI = guard.x - 1; xI > xMax; --xI) {
                            if (find(guardPath.begin(), guardPath.end(), Pos{xI, guard.y}) == guardPath.end()) {
                                guardPath.push_back(Pos{xI, guard.y});
                            }
                        }

                        guard.x = xMax + 1;
                        guard.direction = NORTH;
                    } else {
                        for (int xI = guard.x - 1; xI >= 0; --xI) {
                            if (find(guardPath.begin(), guardPath.end(), Pos{xI, guard.y}) == guardPath.end()) {
                                guardPath.push_back(Pos{xI, guard.y});
                            }
                        }
                        isOut = true;
                    }

                    break;
                }
            }
        }

        cout << guardPath.size() << endl;
    }
}

void partTwo() {
    if (ifstream fs("../inputs/puzzle2.txt"); fs.is_open()) {
        int result = 0;
        vector<Pos> positions;
        GuardPos guard;
        Pos gridSize;

        string line;
        int y = 0;
        while (getline(fs, line)) {
            gridSize.x = line.size();
            for (int x = 0; x < line.size(); ++x) {
                if (line[x] == '#') positions.push_back(Pos{x, y});
                if (line[x] == '^') {
                    guard = GuardPos{x, y, NORTH};
                }
            }
            ++y;
        }
        gridSize.y = y;

        GuardPos initialGuard = GuardPos{guard.x, guard.y, guard.direction};

        for (y = 0; y < gridSize.y; ++y) {
            for (int x = 0; x < gridSize.x; ++x) {
                positions.push_back(Pos{x, y});

                vector<GuardPos> stopPos;

                bool isOut = false;
                while (!isOut) {
                    switch (guard.direction) {
                        case NORTH : {
                            int yMax = -1;
                            for (int i = 0; i < positions.size(); ++i) {
                                if (positions[i].x == guard.x && positions[i].y > yMax && positions[i].y < guard.y) yMax = positions[i].y;
                            }

                            if (yMax != -1) {
                                guard.y = yMax + 1;
                                guard.direction = EAST;

                                if (find(stopPos.begin(), stopPos.end(), GuardPos{guard.x, guard.y, guard.direction}) != stopPos.end()) {
                                    isOut = true;
                                    ++result;
                                } else {
                                    stopPos.push_back(GuardPos{guard.x, guard.y, guard.direction});
                                }
                            } else {
                                isOut = true;
                            }

                            break;
                        }

                        case EAST : {
                            int xMin = gridSize.x + 1;
                            for (int i = 0; i < positions.size(); ++i) {
                                if (positions[i].y == guard.y && positions[i].x < xMin && positions[i].x > guard.x) xMin = positions[i].x;
                            }

                            if (xMin != gridSize.x + 1) {
                                guard.x = xMin - 1;
                                guard.direction = SOUTH;

                                if (find(stopPos.begin(), stopPos.end(), GuardPos{guard.x, guard.y, guard.direction}) != stopPos.end()) {
                                    isOut = true;
                                    ++result;
                                } else {
                                    stopPos.push_back(GuardPos{guard.x, guard.y, guard.direction});
                                }
                            } else {
                                isOut = true;
                            }

                            break;
                        }

                        case SOUTH : {
                            int yMin = gridSize.y + 1;
                            for (int i = 0; i < positions.size(); ++i) {
                                if (positions[i].x == guard.x && positions[i].y < yMin && positions[i].y > guard.y) yMin = positions[i].y;
                            }

                            if (yMin != gridSize.y + 1) {
                                guard.y = yMin - 1;
                                guard.direction = WEST;

                                if (find(stopPos.begin(), stopPos.end(), GuardPos{guard.x, guard.y, guard.direction}) != stopPos.end()) {
                                    isOut = true;
                                    ++result;
                                } else {
                                    stopPos.push_back(GuardPos{guard.x, guard.y, guard.direction});
                                }
                            } else {
                                isOut = true;
                            }

                            break;
                        }

                        case WEST : {
                            int xMax = -1;
                            for (int i = 0; i < positions.size(); ++i) {
                                if (positions[i].y == guard.y && positions[i].x > xMax && positions[i].x < guard.x) xMax = positions[i].x;
                            }

                            if (xMax != -1) {
                                guard.x = xMax + 1;
                                guard.direction = NORTH;

                                if (find(stopPos.begin(), stopPos.end(), GuardPos{guard.x, guard.y, guard.direction}) != stopPos.end()) {
                                    isOut = true;
                                    ++result;
                                } else {
                                    stopPos.push_back(GuardPos{guard.x, guard.y, guard.direction});
                                }
                            } else {
                                isOut = true;
                            }

                            break;
                        }
                    }
                }

                positions.pop_back();
                guard.x = initialGuard.x;
                guard.y = initialGuard.y;
                guard.direction = initialGuard.direction;
            }
        }

        cout << result << endl;
    }
}