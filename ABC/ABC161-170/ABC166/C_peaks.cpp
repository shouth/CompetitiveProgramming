#include<bits/stdc++.h>
using namespace std;

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 n, m;
    cin >> n >> m;
    vector<i64> hs(n);
    for (auto& h : hs) cin >> h;
    vector<i64> is(n);
    iota(begin(is), end(is), 0);
    sort(begin(is), end(is), [&](i64 i, i64 j) { return hs[i] > hs[j]; });

    vector<vector<i64>> p(n);
    for (i64 i = 0; i < m; i++) {
        i64 a, b;
        cin >> a >> b, a--, b--;
        p[a].emplace_back(b);
        p[b].emplace_back(a);
    }

    i64 ans = 0;
    vector<i64> g(n);
    for (auto& i : is) {
        if (g[i]) continue;
        g[i] = 1;
        for (auto& j : p[i]) g[j] = 1;
        ans += all_of(begin(p[i]), end(p[i]), [&](i64 j) { return hs[i] > hs[j]; });
    }

    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
