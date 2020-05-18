#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 n;
    cin >> n;
    vector<i64> a(n + 1, 0);
    for (i64 i = 1; i <= n; i++) cin >> a[i];
    partial_sum(all(a), begin(a));
    map<i64, i64> cnt;
    i64 ans = 0;
    for (auto& e : a) ans += cnt[e], cnt[e]++;
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
