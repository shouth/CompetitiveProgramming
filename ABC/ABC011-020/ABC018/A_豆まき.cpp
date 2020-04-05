#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<pair<int, int>> abc(3);
    for (int i = 0; i < 3; i++) {
        int t;
        cin >> t;
        abc[i] = { t, i };
    }

    sort(begin(abc), end(abc), greater<>());
    vector<int> ans(3);
    for (int i = 0; i < 3; i++) ans[abc[i].second] = i+1;
    for (auto& e : ans) cout << e << endl; 
}
