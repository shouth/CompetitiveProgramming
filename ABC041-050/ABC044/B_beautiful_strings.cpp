#include<bits/stdc++.h>
using namespace std;

int main() {
    string w;
    cin >> w;
    map<char, int> c;
    for (auto& e : w) c[e]++;
    string ans = "Yes";
    for (auto& e : c) if (e.second % 2 == 1) ans = "No";
    cout << ans << endl;
}
