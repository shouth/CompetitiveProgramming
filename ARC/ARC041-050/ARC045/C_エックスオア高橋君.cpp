#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 n, x;
    cin >> n >> x;
    vector<vector<p64>> t(n);
    for (i64 i = 0; i < n - 1; i++) {
        i64 xi, yi, ci;
        cin >> xi >> yi >> ci, xi--, yi--;
        t[xi].emplace_back(yi, ci);
        t[yi].emplace_back(xi, ci);
    }

    vector<i64> sum(n, -1);
    queue<p64> q;
    q.emplace(0, 0);
    while (!q.empty()) {
        auto [ cur, s ] = q.front(); q.pop();
        sum[cur] = s;
        for (auto& [ nxt, c ] : t[cur]) {
            if (sum[nxt] == -1) q.emplace(nxt, s ^ c);
        }
    }

    map<i64, i64> cnt;
    for (auto& e : sum) cnt[e]++;

    i64 ans = 0;
    for (auto& [ s, c ] : cnt) ans += x ? c * cnt[x ^ s] : c * (c - 1);
    cout << ans / 2 << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
