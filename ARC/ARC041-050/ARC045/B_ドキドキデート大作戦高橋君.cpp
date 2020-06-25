#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 n, m;
    cin >> n >> m;
    vector<p64> st(m);
    vector<i64> r(n + 2);
    for (auto& [ s, t ] : st) {
        cin >> s >> t;
        r[s] += 1, r[t + 1] -= 1;
    }
    partial_sum(all(r), begin(r));
    for (auto& e : r) e = e > 1;
    partial_sum(all(r), begin(r));

    vector<i64> ans;
    for (i64 i = 0; i < m; i++) {
        auto [ s, t ] = st[i];
        if (r[t] - r[s - 1] == t - (s - 1)) ans.emplace_back(i + 1);
    }
    cout << ans.size() << endl;
    for (auto& e : ans) cout << e << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
