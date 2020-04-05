#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    reverse(begin(s), end(s));
    vector<string> w { "dream", "dreamer", "erase", "eraser" };
    for (auto& e : w) reverse(begin(e), end(e));

    int pos = 0, ppos = -1;
    while (ppos != pos) {
        ppos = pos;
        for (auto& e : w) if (s.substr(pos, e.size()) == e) pos += e.size();
    }

    cout << (pos == (int) s.size() ? "YES" : "NO") << endl;
}
