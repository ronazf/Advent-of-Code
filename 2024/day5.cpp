#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
using namespace std;

map<int, vector<int>> getRuleDict() {
    string input;
    map<int, vector<int>> dict;
    while(getline(cin, input)) {
        istringstream stream(input);
        int key;
        while (stream >> key) {
            char c;
            int val;

            stream >> c;
            stream >> val;

            if (dict.find(key) == dict.end()) {
                dict.insert({key, {val}});
            } else {
                dict[key].push_back(val);
            }
        }

        if (input == "") {
            break;
        }
    }

    return dict;
}

vector<vector<int>> getUpdateVector() {
    vector<vector<int>> vec;

    string input;
    while(getline(cin, input)) {
        vector<int> intVec;
        istringstream stream(input);
        int num;
        while (stream >> num) {
            intVec.push_back(num);

            char c;
            stream >> c;
        }

        vec.push_back(intVec);
    }

    return vec;
}

int getUpdateNum(const map<int, vector<int>> &ruleDict, const vector<vector<int>> &updateVec) {
    int res = 0;

    for (auto &vec: updateVec) {
        bool valid = true;
        set<int> updateVals;
        for (auto &val: vec) {
            if (ruleDict.find(val) != ruleDict.end()) {
                for (auto &ruleVal: ruleDict.at(val)) {
                    if (updateVals.find(ruleVal) != updateVals.end()) {
                        valid = false;
                        break;
                    }
                }
            }
            updateVals.insert(val);
        }

        if (valid) {
            res += vec[vec.size() / 2];
        }
    }

    return res;
}

int main() {
    int res = 0;
    map<int, vector<int>> ruleDict = getRuleDict();
    vector<vector<int>> updateVec = getUpdateVector();

    res = getUpdateNum(ruleDict, updateVec);

    cout << "Update result is: " << res << endl;

    return 0;
}