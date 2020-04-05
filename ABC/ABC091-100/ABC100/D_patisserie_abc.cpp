#include<bits/stdc++.h>
using namespace std;


int main() {
    int64_t n, m;
    cin >> n >> m;
    vector<vector<int64_t>> xyz(n, vector<int64_t>(3));
    for (auto& e : xyz) for (auto& f : e) cin >> f;

    int64_t ans = 0;
    for (int s = 0; s < 8; s++) {
        vector<pair<int64_t, int64_t>> sum(n);
        for (int i = 0; i < n; i++) {
            sum[i].second = i;
            for (int j = 0; j < 3; j++) sum[i].first += xyz[i][j] * ((s & (1 << j)) ? 1 : -1);
        }
        sort(begin(sum), end(sum), greater<>());

        vector<int64_t> can(3);
        for (int64_t i = 0; i < 3; i++) {
            for (int64_t j = 0; j < m; j++) can[i] += xyz[sum[j].second][i];
        }

        ans = max(ans, abs(can[0]) + abs(can[1]) + abs(can[2]));
    }

    cout << ans << endl;
}
