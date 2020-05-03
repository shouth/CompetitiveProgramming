#include<bits/stdc++.h>
using namespace std;

using i64 = int_fast64_t;
using f64 = double;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

i64 n;
vector<i64> a;
vector<i64> d;
vector<vector<i64>> g;
vector<i64> p;

void dfs(i64 x) {
    i64 idx = lower_bound(begin(p), end(p), a[x]) - begin(p);
    i64 s = p.size();
    if (idx != s) {
        swap(p[idx], a[x]);
    } else {
        p.push_back(a[x]);
    }

    d[x] = p.size();
    for (auto& e : g[x]) {
        if (d[e] == -1) dfs(e);
    }

    if (idx != s) {
        swap(p[idx], a[x]);
    } else {
        p.pop_back();
    }
}

void solve() {
    cin >> n;
    a.resize(n);
    for (auto& e : a) cin >> e;
    g.resize(n);
    for (i64 i = 0; i < n - 1; i++) {
        i64 u, v;
        cin >> u >> v, u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    d.resize(n, -1);
    dfs(0);
    for (auto& e : d) cout << e << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
