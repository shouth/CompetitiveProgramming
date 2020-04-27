#include<bits/stdc++.h>
using namespace std;

using i64 = int_fast64_t;
using f64 = double;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 n, m;
    cin >> n >> m;
    vector<vector<i64>> g(n);
    vector<i64> in(n), a(n - 1 + m), b(n - 1 + m);
    for (i64 i = 0; i < n - 1 + m; i++) {
        cin >> a[i] >> b[i], a[i]--, b[i]--;
        g[a[i]].push_back(b[i]);
        in[b[i]]++;
    }

    i64 r = distance(begin(in), find(begin(in), end(in), 0));
    vector<i64> dist(n, 0);
    queue<i64> q;
    q.push(r);
    while (!q.empty()) {
        i64 t = q.front(); q.pop();
        for (auto& e : g[t]) {
            in[e]--;
            dist[e] = max(dist[e], dist[t] + 1);
            if (in[e] == 0) q.push(e);
        }
    }

    vector<i64> ans(n, -1);
    for (i64 i = 0; i < n - 1 + m; i++) {
        if (dist[b[i]] - dist[a[i]] == 1) ans[b[i]] = a[i];
    }
    for (auto& e : ans) cout << e + 1 << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
