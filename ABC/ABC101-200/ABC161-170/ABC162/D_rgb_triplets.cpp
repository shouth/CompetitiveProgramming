#include<bits/stdc++.h>
using namespace std;

using i32 = int_fast32_t;
using i64 = int_fast64_t;

int main() {
    i64 n;
    cin >> n;
    string s;
    cin >> s;

    map<char, i64> c;
    for (auto& e : s) c[e]++;

    i64 ans = c['R'] * c['G'] * c['B'];
    for (i32 d = 1; d < n; d++) {
        for (i32 i = d; i + d < n; i++) {
            if (s[i-d] != s[i] && s[i] != s[i+d] && s[i+d] != s[i-d]) ans--;
        }
    }

    cout << ans << endl;
}
