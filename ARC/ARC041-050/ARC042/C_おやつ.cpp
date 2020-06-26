#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 n, p;
    cin >> n >> p;
    vector<p64> ab(n);
    for (auto& [ a, b ] : ab) cin >> a >> b;
    sort(all(ab), greater());

    vector<i64> dp(p + 110);
    for (i64 i = 0; i < n; i++) {
        for (i64 j = p; j >= 0; j--) {
            auto [ a, b ] = ab[i];
            dp[j + a] = max(dp[j + a], dp[j] + b);
        }
    }
    cout << *max_element(all(dp)) << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
