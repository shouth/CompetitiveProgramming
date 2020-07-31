#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

struct cost {
    i64 dest;
    i64 yen, snuuk;
};

void solve() {
    i64 n, m, s, t;
    cin >> n >> m >> s >> t, s--, t--;

    vector<vector<cost>> g(n);
    for (i64 i = 0; i < m; i++) {
        i64 u, v, a, b;
        cin >> u >> v >> a >> b, u--, v--;
        g[u].push_back({ v, a, b });
        g[v].push_back({ u, a, b });
    }

    vector<i64> minyen(n, INF), minsnuuk(n, INF);
    priority_queue<p64, vector<p64>, greater<>> pq;
    pq.emplace(0, s);
    while (!pq.empty()) {
        auto [ cost, to ] = pq.top(); pq.pop();
        if (minyen[to] != INF) continue;
        minyen[to] = cost;

        for (auto& [ dest, yen, snuuk ] : g[to]) {
            if (minyen[dest] != INF) continue;
            pq.emplace(cost + yen, dest);
        }
    }
    pq.emplace(0, t);
    while (!pq.empty()) {
        auto [ cost, to ] = pq.top(); pq.pop();
        if (minsnuuk[to] != INF) continue;
        minsnuuk[to] = cost;

        for (auto& [ dest, yen, snuuk ] : g[to]) {
            if (minsnuuk[dest] != INF) continue;
            pq.emplace(cost + snuuk, dest);
        }
    }

    for (i64 i = 0; i < n; i++) {
        pq.emplace(minyen[i] + minsnuuk[i], i);
    }

    for (i64 i = 0; i < n; i++) {
        while (pq.top().second < i) pq.pop();
        cout << (i64) 1e15 - pq.top().first << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
