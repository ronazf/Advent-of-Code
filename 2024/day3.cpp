#include <iostream>
using namespace std;

int main () {
    int mulRes = 0;

    string doStr = "do()";
    string dontStr = "don't()";
    bool enabled = true;

    string mulStr = "mul(";
    char charBet = ',';
    char charEnd = ')';
    char c;
    string s;
    while (cin >> c) {
        s = s + c;
        if (s != mulStr.substr(0, s.size()) &&
            s != doStr.substr(0, s.size()) && 
            s != dontStr.substr(0, s.size())) {
            s = "";
        }

        if (s == doStr) {
            enabled = true;
            s = "";
        }

        if (s == dontStr) {
            enabled = false;
            s = "";
        }

        if (s == mulStr) {
            int a;
            char bet;
            int b;
            char end;

            if (cin >> a && cin >> bet && bet == charBet && cin >> b && cin >> end && end == charEnd) {
                mulRes += a * b * enabled;
            }

            s = "";
        }
    }

    cout << "mul result is: " << mulRes << endl;

    return 0;
}