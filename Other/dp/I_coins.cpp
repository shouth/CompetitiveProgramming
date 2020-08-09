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
    vector<f64> p(n);
    for (auto& e : p) cin >> e;

    vector<f64> dp(n + 1);
    dp[0] = 1;
    for (i64 i = 0; i < n; i++) {
        for (i64 j = n; j > 0; j--) {
            dp[j] += dp[j - 1] * p[i];
            dp[j - 1] *= 1 - p[i];
        }
    }

    cout << accumulate(begin(dp) + (n + 1) / 2, end(dp), 0.0) << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
