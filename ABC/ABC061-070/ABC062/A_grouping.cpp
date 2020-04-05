#include<bits/stdc++.h>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    vector<vector<int>> g { { 1, 3, 5, 7, 8, 10, 12 }, { 4, 6, 9, 11 }, { 2 } };
    string ans = "No";
    for (auto& e : g) {
        auto xin = find(begin(e), end(e), x);
        auto yin = find(begin(e), end(e), y);
        if (xin != end(e) && yin != end(e)) ans = "Yes";
    }
    cout << ans << endl;
}
