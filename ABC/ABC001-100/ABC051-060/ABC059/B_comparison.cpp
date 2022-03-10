#include<bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    if (a.size() != b.size()) {
        cout << (a.size() > b.size() ? "GREATER" : "LESS") << endl;
    } else if (a != b) {
        cout << (a > b ? "GREATER" : "LESS") << endl;
    } else {
        cout << "EQUAL" << endl;
    }
}
