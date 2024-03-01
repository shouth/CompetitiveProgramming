#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int a = 0, b = 0;
    for(int i=0; i<s.size(); i++) {
        if (i % 2 != 0) {
            if (s[i] != '0') a++;
            else b++;
        } else {
            if (s[i] != '1') a++;
            else b++;
        }
    }
    cout << min(a, b) << endl;
}