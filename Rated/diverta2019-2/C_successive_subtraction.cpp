#include<bits/stdc++.h>
using namespace std;

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 n;
    cin >> n;
    vector<i64> a(n);
    for (auto& e : a) cin >> e;
    sort(begin(a), end(a));
    
    vector<p64> ans;
    i64 b = lower_bound(begin(a), end(a), 0l) - begin(a);
    if (b == 0) b++;
    if (b == n) b--;
    for (i64 i = b; i < n - 1; i++) {
        ans.emplace_back(a[0], a[i]);
        a[0] -= a[i];
    }
    for (i64 i = 0; i < b; i++) {
        ans.emplace_back(a[n - 1], a[i]);
        a[n - 1] -= a[i];
    }
    cout << a[n - 1] << endl;
    for (auto& e : ans) cout << e.first << " " << e.second << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
