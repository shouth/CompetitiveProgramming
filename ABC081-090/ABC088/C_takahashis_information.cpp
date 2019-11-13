#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> c(3, vector<int>(3));
    for (auto& e : c) for (auto& f : e) cin >> f;

    string ans = "Yes";
    for (int i = 0; i + 1 < 3; i++) {
        vector<int> v = { c[0][i+1] - c[0][i], c[1][i+1] - c[1][i], c[2][i+1] - c[2][i] };
        vector<int> w = { c[i+1][0] - c[i][0], c[i+1][1] - c[i][1], c[i+1][2] - c[i][2] };
        for (auto& e : { v, w }) {
            if (adjacent_find(begin(v), end(v), not_equal_to<>()) != end(v)) ans = "No";
        }
    }

    cout << ans << endl;
}
