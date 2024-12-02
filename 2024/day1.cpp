#include <iostream>
#include <vector>
using namespace std;

int getDistance() {
    int res = 0;
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

    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());

    for (int i = 0; i < vec1.size(); i++) {
        res += abs(vec1.at(i) - vec2.at(i));
    }

    return res;
}

int main () {
    int distance = getDistance();

    cout << "Distance is: " << distance << endl;

    return 0;
}