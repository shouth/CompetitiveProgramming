#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> ab(n);
    for (auto& e : ab) cin >> e.first >> e.second;
    vector<pair<int, int>> cd(m);
    for (auto& e : cd) cin >> e.first >> e.second;
    for (auto& e : ab) {
        int can = -1, tmp = 1e9;
        for (int i = 0; i < m; i++) {
            int dist = abs(e.first - cd[i].first) + abs(e.second - cd[i].second);
            if (dist < tmp) tmp = dist, can = i + 1;
        }
        cout << can << endl;
    }
}
