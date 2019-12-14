#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int t;
    cin >> t;
    map<char, int> m;
    for (auto& e : s) m[e]++;
    int ans = abs(m['L'] - m['R']) + abs(m['U'] - m['D']) + m['?'] * (t == 1 ? 1 : -1);
    cout << (ans >= 0 ? ans : abs(ans) % 2) << endl;
}
