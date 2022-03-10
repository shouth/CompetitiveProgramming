#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 n;
    cin >> n;
    vector<i64> a(n);
    for (auto& e : a) cin >> e;
    sort(all(a), greater<>());

    n--;
    i64 ans = a[0];
    for (i64 i = 0; i < (n - 1) / 2; i++) {
        ans += a[i + 1] * 2;
    }
    if (n % 2 == 0) ans += a[n / 2];
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
