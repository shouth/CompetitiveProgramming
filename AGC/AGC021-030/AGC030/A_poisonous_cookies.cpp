#include<bits/stdc++.h>
using namespace std;

using i64 = int_fast64_t;
using f64 = double;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 a, b, c;
    cin >> a >> b >> c;

    i64 ans = 0;
    i64 d = min(b, c);
    ans += d + b, c -= d;
    i64 e = min(a, c);
    ans += e + (c > e);
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
