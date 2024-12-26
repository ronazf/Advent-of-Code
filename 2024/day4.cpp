#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

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

int xmasNum(const vector<vector<char>> &vecList) {
    int res = 0;

    string xmas = "XMAS";
    string xmasRev = "SAMX";

    for (int i = 0; i < vecList.size(); i++) {
        for (int j = 0; j < vecList[i].size(); j++) {
            if (j + 3 < vecList[i].size()) {
                string str = string(1, vecList[i][j]) +
                             string(1, vecList[i][j + 1]) + 
                             string(1, vecList[i][j + 2]) + 
                             string(1, vecList[i][j + 3]);

                res += str == xmas || str == xmasRev;
            }
            if (j + 3 < vecList[i].size() && i + 3 < vecList.size()) {
                string str = string(1, vecList[i][j]) +
                             string(1, vecList[i + 1][j + 1]) + 
                             string(1, vecList[i + 2][j + 2]) + 
                             string(1, vecList[i + 3][j + 3]);
                    
                res += str == xmas || str == xmasRev;
            }
            if (i + 3 < vecList.size()) {
                string str = string(1, vecList[i][j]) +
                             string(1, vecList[i + 1][j]) + 
                             string(1, vecList[i + 2][j]) + 
                             string(1, vecList[i + 3][j]);
                    
                res += str == xmas || str == xmasRev;
            }
            if (j - 3 >= 0 && i + 3 < vecList.size()) {
                string str = string(1, vecList[i][j]) +
                             string(1, vecList[i + 1][j - 1]) + 
                             string(1, vecList[i + 2][j - 2]) + 
                             string(1, vecList[i + 3][j - 3]);
                    
                res += str == xmas || str == xmasRev;
            }
        }
    }

    return res;
}

int masNum(const vector<vector<char>> &vecList) {
    int res = 0;

    string ms = "MS";
    string msRev = "SM";

    for (int i = 0; i < vecList.size(); i++) {
        for (int j = 0; j < vecList[i].size(); j++) {
            if (vecList[i][j] != 'A') {
                continue;
            }

            if (j + 1 < vecList[i].size() && j - 1 >= 0 && i + 1 < vecList.size() && i - 1 >= 0) {
                string left = string(1, vecList[i - 1][j - 1]) + string(1, vecList[i + 1][j + 1]);
                string right = string(1, vecList[i - 1][j + 1]) + string(1, vecList[i + 1][j - 1]);
                res += (left == ms || left == msRev) && (right == ms || right == msRev);
            }
        }
    }

    return res;
}

int main() {

    vector<vector<char>> vecList = getVector();

    int res = xmasNum(vecList);
    int masRes = masNum(vecList);

    cout << "X-MAS score is: " << masRes << endl;

    return 0;
}
