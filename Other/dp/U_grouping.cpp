#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 n;
    cin >> n;
    vector<vector<i64>> a(n, vector<i64>(n));
    for (auto& e : a) for (auto& f : e) cin >> f;

    vector<i64> dp(1 << n, -1);
    auto f = [&](auto g, i64 t) {
        if (dp[t] != -1) return dp[t];

        i64 res = 0;
        for (i64 i = 0; i < n; i++) {
            for (i64 j = i + 1; j < n; j++) {
                if ((t >> i) & 1 && (t >> j) & 1) res += a[i][j];
            }
        }

        for (i64 u = (1 << n) - 1; u >= 0; u--) {
            u &= t;
            if (u != t && (t ^ u) != t) res = max(res, g(g, u) + g(g, t ^ u));
        }

        return dp[t] = res;
    };

    cout << f(f, (1 << n) - 1) << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
