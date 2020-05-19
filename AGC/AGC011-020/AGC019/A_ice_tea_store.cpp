#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 q, h, s, d;
    cin >> q >> h >> s >> d;
    i64 n;
    cin >> n, n *= 4;

    d = min(d, 2 * s);
    d = min(d, 4 * h);
    d = min(d, 8 * q);
    s = min(s, 2 * h);
    s = min(s, 4 * q);
    h = min(h, 2 * q);

    i64 ans = 0;
    ans += n / 8 * d, n %= 8;
    ans += n / 4 * s, n %= 4;
    ans += n / 2 * h, n %= 2;
    ans += n / 1 * q, n %= 1;
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
