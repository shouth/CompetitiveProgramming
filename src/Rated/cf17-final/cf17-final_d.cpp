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
    i64 n;
    cin >> n;
    vector<i64> d(n + 1);
    for (i64 i = 0; i < n; i++) cin >> d[i];
    sort(all(d));

    for (i64 i = 0; i < n + 1; i++) {
        if (i % 2) d[i] = -d[i];
    }
    sort(all(d));

    i64 ans = d.back() - d.front();
    ans = min(ans, 24 - ans);
    for (i64 i = 0; i + 1 < n + 1; i++) {
        ans = min(ans, d[i + 1] - d[i]);
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
