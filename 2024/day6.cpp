#include <iostream>
#include<sstream>
#include <vector>
using namespace std;

const string UP = "up";
const string RIGHT = "right";
const string DOWN = "down";
const string LEFT = "left";

vector<vector<char>> getVector() {
    vector<vector<char>> vec;

    string input;
    while(getline(cin, input)) {
        vector<char> charVec;
        istringstream stream(input);
        char c;
        while (stream >> c) {
            charVec.push_back(c);
        }

        vec.push_back(charVec);
    }

    return vec;
}

int main() {
    int res = 0;

    vector<vector<char>> vecList = getVector();
    int iCur = -1;
    int jCur = -1;
    string dir = UP;


    for (int i = 0; i < vecList.size(); i++) {
        auto it = find(vecList[i].begin(), vecList[i].end(), '^');
        if (it != vecList[i].end()) {
            iCur = i;
            jCur = distance(vecList[i].begin(), it);
        }
    }

    res += 1;
    vecList[iCur][jCur] = 'X';

    while ((iCur != vecList.size() - 1 && iCur != 0) && (jCur != vecList[0].size() - 1 && jCur != 0)) {
        if (dir == UP) {
            while (iCur - 1 >= 0 && vecList[iCur - 1][jCur] != '#') {
                iCur -= 1;

                if (vecList[iCur][jCur] != 'X') {
                    res += 1;
                    vecList[iCur][jCur] = 'X';
                }
            }

            if (iCur == 0) {
                break;
            } else {
                dir = RIGHT;
            }
        } else if (dir == RIGHT) {
            while (jCur + 1 < vecList[0].size() && vecList[iCur][jCur + 1] != '#') {
                jCur += 1;


                if (vecList[iCur][jCur] != 'X') {
                    res += 1;
                    vecList[iCur][jCur] = 'X';
                }
            }

            if (jCur == vecList[0].size() - 1) {
                break;
            } else {
                dir = DOWN;
            }
        } else if (dir == DOWN) {
            while (iCur + 1 < vecList.size() && vecList[iCur + 1][jCur] != '#') {
                iCur += 1;

                if (vecList[iCur][jCur] != 'X') {
                    res += 1;
                    vecList[iCur][jCur] = 'X';
                }
            }

            if (iCur == vecList.size() - 1) {
                break;
            } else {
                dir = LEFT;
            }
        } else {
            while (jCur - 1 >= 0 && vecList[iCur][jCur - 1] != '#') {
                jCur -= 1;

                if (vecList[iCur][jCur] != 'X') {
                    res += 1;
                    vecList[iCur][jCur] = 'X';
                }
            }

            if (jCur == 0) {
                break;
            } else {
                dir = UP;
            }
        }
    }

    cout << "Distinct positions visited: " << res << endl;

    return 0;
}