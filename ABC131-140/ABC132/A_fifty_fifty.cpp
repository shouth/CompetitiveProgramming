#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    map<char, int> m;

    for (auto& e : s) {
        m[e]++;
    }

    cout << (m.size() == 2 && all_of(m.begin(), m.end(), [&](auto a){ return a.second == 2; }) ? "Yes" : "No") << endl;
}
