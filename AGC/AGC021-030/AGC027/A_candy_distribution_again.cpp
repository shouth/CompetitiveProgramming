#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using f64 = double;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 n, x;
    cin >> n >> x;
    vector<i64> a(n);
    for (auto& e : a) cin >> e;
    sort(all(a));
    partial_sum(all(a), begin(a));
    i64 ans = upper_bound(all(a), x) - begin(a);
    if (a[n - 1] < x) ans--;
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
