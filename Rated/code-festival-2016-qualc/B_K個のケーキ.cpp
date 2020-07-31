#include<bits/stdc++.h>
using namespace std;

using i64 = int_fast64_t;
using f64 = double;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 k, t;
    cin >> k >> t;

    i64 ans = 0;
    for (i64 i = 0; i < t; i++) {
        i64 a;
        cin >> a;
        if (a > (k + 1) / 2) ans = k - 2 * (k - a) - 1;
    }

    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
