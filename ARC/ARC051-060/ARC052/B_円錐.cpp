#include <utility>
#include <bitset>
#include <tuple>
#include <string>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <complex>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 n, q;
    cin >> n >> q;
    vector<tuple<f64, f64, f64>> xrh(n);
    for (auto& [ x, r, h ] : xrh) cin >> x >> r >> h;
    sort(all(xrh));

    for (i64 i = 0; i < q; i++) {
        f64 a, b;
        cin >> a >> b;

        f64 ans = 0;
        for (auto& [ x, r, h ] : xrh) {
            if (x + h <= a || x >= b) continue;
            f64 ah = h - max(0.0, a - x);
            f64 ar = r * ah / h;
            ans += M_PI * ar * ar * ah / 3.0;
            f64 bh = max(0.0, x + h - b);
            f64 br = r * bh / h;
            ans -= M_PI * br * br * bh / 3.0;
        }
        cout << ans << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
