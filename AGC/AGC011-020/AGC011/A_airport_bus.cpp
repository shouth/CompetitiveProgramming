#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 n, c, k;
    cin >> n >> c >> k;
    vector<i64> t(n);
    for (auto& e : t) cin >> e;
    sort(all(t));

    i64 l = 0, r = 0;
    i64 ans = 0;
    while (r < n) {
        while (r < n && r - l < c && t[r] - t[l] <= k) r++;
        ans++, l = r;
    }

    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
