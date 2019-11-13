#include<bits/stdc++.h>
using namespace std;

int main() {
    map<string, int> ss;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        ss[s]++;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        string t;
        cin >> t;
        ss[t]--;
    }
    auto c = *max_element(begin(ss), end(ss), [](auto a, auto b) { return a.second < b.second; });
    cout << max(c.second, 0) << endl;
}
