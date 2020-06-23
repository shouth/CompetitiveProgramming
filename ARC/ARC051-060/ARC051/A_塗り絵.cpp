#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    f64 cx, cy, r;
    cin >> cx >> cy >> r;
    f64 sx1, sy1, sx2, sy2;
    cin >> sx1 >> sy1 >> sx2 >> sy2;

    cout << (cx - r < sx1 || cx + r > sx2 || cy - r < sy1 || cy + r > sy2 ? "YES" : "NO") << endl;
    cout << (hypot(sx1 - cx, sy1 - cy) > r || hypot(sx1 - cx, sy2 - cy) > r || hypot(sx2 - cx, sy1 - cy) > r || hypot(sx2 - cx, sy2 - cy) > r ? "YES" : "NO") << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
