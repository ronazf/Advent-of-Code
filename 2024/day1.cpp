#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> getVectors() {
    vector<int> vec1, vec2;

    int i = 0;
    int num;
    while(cin >> num) {
        if (i % 2 == 0) {
            vec1.push_back(num);
        } else {
            vec2.push_back(num);
        }
        i++;
    }

    return {vec1, vec2};
}

int getDistance(vector<int> vec1, vector<int> vec2) {
    int res = 0;

    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());

    for (int i = 0; i < vec1.size(); i++) {
        res += abs(vec1[i] - vec2[i]);
    }

    return res;
}

int getSimilarity(vector<int> vec1, vector<int> vec2) {
    int res = 0;

    for (int i = 0; i < vec1.size(); i++) {
        res += vec1[i] * count(vec2.begin(), vec2.end(), vec1[i]);
    }

    return res;
}

int main () {
    vector<vector<int>> vecList = getVectors();
    int distance = getDistance(vecList[0], vecList[1]);
    int similarity = getSimilarity(vecList[0], vecList[1]);

    cout << "Distance is: " << distance << endl;
    cout << "Similarity score is: " << similarity << endl;

    return 0;
}