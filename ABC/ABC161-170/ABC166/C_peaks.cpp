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
    vector<p64> his(n);
    for (i64 i = 0; i < n; i++) {
        cin >> hs[i];
        his[i] = { hs[i], i };
    }

    sort(begin(his), end(his), greater());

    vector<vector<i64>> p(n);
    for (i64 i = 0; i < m; i++) {
        i64 a, b;
        cin >> a >> b, a--, b--;
        p[a].emplace_back(b);
        p[b].emplace_back(a);
    }

    vector<i64> g(n, -1);
    for (auto& e : his) {
        i64 h, i;
        tie(h, i) = e;
        if (g[i] != -1) continue;
        i64 res = 1;
        for (auto& j : p[i]) {
            g[j] = 0;
            res &= h > hs[j];
        }
        g[i] = res;
    }

    cout << accumulate(begin(g), end(g), 0l) << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
