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
    vector<f64> x(n), y(n), c(n);
    for (i64 i = 0; i < n; i++) cin >> x[i] >> y[i] >> c[i];

    f64 left = 0, right = (f64) INF;
    while (abs(right - left) > 1e-5) {
        f64 mid = (left + right) / 2;
        f64 minx = -1e5, maxx = 1e5, miny = -1e5, maxy = 1e5;
        for (i64 i = 0; i < n; i++) {
            f64 l = mid / c[i];
            minx = max(minx, x[i] - l), maxx = min(maxx, x[i] + l);
            miny = max(miny, y[i] - l), maxy = min(maxy, y[i] + l);
        }

        (minx > maxx || miny > maxy ? left : right) = mid;
    }
    cout << right << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
