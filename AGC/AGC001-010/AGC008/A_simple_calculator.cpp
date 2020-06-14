#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 x, y;
    cin >> x >> y;

    i64 ans = abs(abs(x) - abs(y));
    if (x + ans == y) {
        cout << ans << endl;
    } else if (x * y > 0) {
        cout << ans + 2 << endl;
    } else {
        cout << ans + 1 << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}