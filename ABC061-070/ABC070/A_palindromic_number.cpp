#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    string ans = "Yes";
    for (size_t i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - 1]) ans = "No";
    }
    cout << ans << endl;
}
