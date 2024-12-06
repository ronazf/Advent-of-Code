#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<vector<int>> getVector() {
    vector<vector<int>> vec;

    string input;
    while(getline(cin, input)) {
        vector<int> intVec;
        istringstream stream(input);
        int num;
        while (stream >> num) {
            intVec.push_back(num);
        }

        vec.push_back(intVec);
    }

    return vec;
}

bool getValidity(const vector<int> &vec) {
    int growth = 0, minDist = 1, maxDist = 3;

    for (int i = 1; i < vec.size(); i++) {
        int dist = abs(vec[i] - vec[i - 1]);

        if (dist < minDist || dist > maxDist) {
            return false;
        }
        int relGrowth = (vec[i] - vec[i - 1]) / dist;

        if (growth == 0) {
            growth = relGrowth;
        }

        if (growth != relGrowth) {
            return false;
        }
    }

    return true;

}

int main () {
    vector<vector<int>> vecList = getVector();

    int validNum = 0;
    for (auto &elemnt: vecList) {
        validNum += getValidity(elemnt);
    }

    cout << "Validity score is: " << validNum << endl;

    return 0;
}