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
    vector<i64> a(n), b(n);
    for (i64 i = 0; i < n; i++) cin >> a[i] >> b[i];

    i64 cnt = 0;
    for (i64 i = n - 1; i >= 0; i--) cnt += (b[i] - (a[i] + cnt) % b[i]) % b[i];
    cout << cnt << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
