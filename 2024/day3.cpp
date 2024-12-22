#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

const int MIN_DIST = 1;
const int MAX_DIST = 3;

void mulScan(string s) {
}

int main () {
    int mulRes = 0;

    string mulStr = "mul(";
    char charBet = ',';
    char charEnd = ')';
    char c;
    string s;
    while (cin >> c) {
        s = s + c;
        if (s != mulStr.substr(0, s.size())) {
            s = "";
        }

        if (s == mulStr) {
            int a;
            char bet;
            int b;
            char end;

            if (cin >> a && cin >> bet && bet == charBet && cin >> b && cin >> end && end == charEnd) {
                mulRes += a * b;
            }

            s = "";
        }
    }

    cout << "mul result is: " << mulRes << endl;

    return 0;
}