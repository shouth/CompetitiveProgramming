#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> xy(n);
    for (auto& e : xy) cin >> e.first >> e.second;

    int m = (abs(xy[0].first) + abs(xy[0].second)) % 2;
    for (int i = 1; i < n; i++) {
        if ((abs(xy[i].first) + abs(xy[i].second)) % 2 != m) {
            cout << -1 << endl;
            return 0;
        }
    }

    vector<int> arms;
    for (int i = 30; i >= 0; i--) arms.push_back(1 << i);
    if (m == 0) arms.push_back(1);

    cout << arms.size() << endl;
    for (auto e : arms) cout << e << " ";
    cout << endl;

    for (auto& e : xy) {
        int u = e.first + e.second, v = e.first - e.second;
        string op = "";
        for (auto& d : arms) {
            if (u > 0 && v > 0) u -= d, v -= d, op += 'R';
            else if (u > 0 && v <= 0) u -= d, v += d, op += 'U';
            else if (u <= 0 && v > 0) u += d, v -= d, op += 'D';
            else u += d, v += d, op += 'L';
        }
        cout << op << endl;
    }
}
