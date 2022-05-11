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

void solve() {
    f64 x, y;
    cin >> x >> y;
    i64 n;
    cin >> n;
    vector<f64> cx(n + 1), cy(n + 1);
    for (i64 i = 0; i < n; i++) cin >> cx[i] >> cy[i];
    cx[n] = cx[0], cy[n] = cy[0];

    f64 ans = (f64) INF;
    for (i64 i = 0; i < n; i++) {
        f64 a = cy[i + 1] - cy[i], b = cx[i + 1] - cx[i];
        ans = min(ans, abs(a * (x - cx[i]) - b * (y - cy[i])) / hypot(a, b));
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
