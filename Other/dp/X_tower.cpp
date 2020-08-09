#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

struct block { i64 w, s, v; };

void solve() {
    i64 n;
    cin >> n;

    vector<block> b(n);
    for (auto& [ w, s, v ] : b) cin >> w >> s >> v;
    sort(all(b), [](block &x, block &y) { return x.w + x.s < y.w + y.s; });

    vector<i64> dp(2e4 + 10);
    for (auto& [ w, s, v ] : b) {
        for (i64 i = s; i >= 0; i--) {
            dp[i + w] = max(dp[i + w], dp[i] + v);
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
