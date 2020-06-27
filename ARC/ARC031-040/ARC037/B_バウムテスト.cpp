#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 n, m;
    cin >> n >> m;
    vector<vector<i64>> g(n);
    for (i64 i = 0; i < m; i++) {
        i64 u, v;
        cin >> u >> v, u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    vector<i64> used(n);
    i64 ans = 0;
    for (i64 i = 0; i < n; i++) {
        if (used[i]) continue;
        queue<i64> q;
        q.push(i);
        i64 x = 0, y = 0;
        while (!q.empty()) {
            i64 t = q.front(); q.pop();
            used[t] = 1;
            y++;
            for (auto& e : g[t]) {
                x++;
                if (used[e]) continue;
                q.emplace(e);
            }
        }
        if (x / 2 == y - 1) ans++;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
