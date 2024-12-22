#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

const int MIN_DIST = 1;
const int MAX_DIST = 3;

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

bool distanceRemove(vector<int> &vec, int &index) {
    if (index == vec.size() - 1) {
        vec.erase(vec.begin() + index);
        index--;

        return true;
    }

    int dist = abs(vec[index - 1] - vec[index + 1]);
    if (dist < MIN_DIST || dist > MAX_DIST) {
        vec.erase(vec.begin() + index - 1);
        index--;

        return true;
    }

    vec.erase(vec.begin() + index);
    index--;

    return true;
}

bool growthRemove(vector<int> &vec, int &index, int &growth) {
    if (index == vec.size() - 1) {
        return true;
    }

    int dist = abs(vec[index - 1] - vec[index + 1]);

    if (dist == 0) {
        vec.erase(vec.begin() + index - 1);
        index--;

        return true;
    }

    int relGrowth = (vec[index + 1] - vec[index - 1]) / dist;

    if (growth != relGrowth) {
        vec.erase(vec.begin() + index - 1);
        index--;

        return true;
    }

    vec.erase(vec.begin() + index);
    index--;
    
    return true;
}

bool getValidity(vector<int> &vec) {
    int removed = 0, growth = 0;

    for (int i = 1; i < vec.size(); i++) {
        int dist = abs(vec[i] - vec[i - 1]);

        if (dist < MIN_DIST || dist > MAX_DIST) {
            distanceRemove(vec, i);

            dist = abs(vec[i] - vec[i - 1]);
            if (dist == 0) {
                return false;
            }
            removed++;
        }

        int relGrowth = (vec[i] - vec[i - 1]) / dist;

        if (growth == 0) {
            growth = relGrowth;
        }

        if (growth != relGrowth) {
            growthRemove(vec, i, growth);
            removed++;
        }

        if (removed > 1) {
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