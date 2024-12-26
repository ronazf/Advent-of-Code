#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
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

int main() {
    int res = 0;

    string xmas = "XMAS";
    string xmasRev = "SAMX";

    vector<vector<char>> vecList = getVector();

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

    cout << "XMAS score is: " << res << endl;

    return 0;
}
