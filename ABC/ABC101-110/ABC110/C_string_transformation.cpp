#include<bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    map<char, char> m;
    string ans = "Yes";
    for (int i = 0, n = s.size(), sid = 1, tid = 1; i < n; i++) {
        if (m.find(s[i]) == m.end()) m[s[i]] = t[i];
        if (m[s[i]] != t[i]) ans = "No";
    }

    cout << ans << endl;
}
