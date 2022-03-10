#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    map<char, int> m;
    for (auto& e : s) m[e]++;
    string ans = "None";
    for (char c = 'a'; c < 'z' + 1; c++) {
        if (m[c] == 0) {
            ans = c;
            break;
        }
    }
    cout << ans << endl;
}
