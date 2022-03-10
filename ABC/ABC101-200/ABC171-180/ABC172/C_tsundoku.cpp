#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 n, m, k;
    cin >> n >> m >> k;
    vector<i64> a(n + 1), b(m + 1);
    for (i64 i = 1; i <= n; i++) cin >> a[i];
    for (i64 i = 1; i <= m; i++) cin >> b[i];
    partial_sum(all(a), begin(a));
    partial_sum(all(b), begin(b));

    i64 ans = 0;
    for (i64 i = 0; i <= n; i++) {
        i64 l = k - a[i];
        if (l < 0) break;
        i64 j = upper_bound(all(b), l) - begin(b) - 1;
        ans = max(ans, i + j);
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
