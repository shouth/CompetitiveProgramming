#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k;
    cin >> k;
    char t = s[k-1];
    for (auto& e : s) {
        if (e != t) e = '*';
    }
    cout << s << endl;
}