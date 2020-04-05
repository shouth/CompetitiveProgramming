#include<bits/stdc++.h>
using namespace std;

constexpr int64_t INF = 1e9;

signed main() {
    int64_t n, m;
    cin >> n >> m;
    vector<vector<int64_t>> dist(n, vector<int64_t>(n, INF));
    vector<int64_t> dist0(n, INF);
    for (int64_t i = 0; i < m; i++) {
        int64_t u, v, l;
        cin >> u >> v >> l, u--, v--;
        if (u == 0 || v == 0) dist0[u + v] = l;
        else dist[u][v] = dist[v][u] = l;
    }

    for (int64_t i = 0; i < n; i++) {
        for (int64_t j = 0; j < n; j++) {
            for (int64_t k = 0; k < n; k++) {
                if (dist[j][k] > dist[j][i] + dist[i][k]) {
                    dist[j][k] = dist[j][i] + dist[i][k];
                }
            }
        }
    }

    int64_t can = INF;
    for (int64_t i = 0; i < n; i++) {
        for (int64_t j = 0; j < n; j++) {
            if (i == j) continue;
            can = min(can, dist0[i] + dist[i][j] + dist0[j]);
        }
    }

    cout << (can == INF ? -1 : can) << endl;
}
