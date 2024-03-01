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
    vector<p64> m1, m2;
    for (i64 i = 0; i < n; i++) {
        i64 a, b;
        cin >> a >> b;
        (a < b ? m1 : m2).emplace_back(a, b);
    }

    sort(all(m1));
    sort(all(m2), [](p64 x, p64 y) { return x.second > y.second; });

    i64 tmp = 0, ans = 0;
    for (auto& m : { m1, m2 }) {
        for (auto& [ a, b ] : m) {
            tmp += a;
            ans = max(ans, tmp);
            tmp -= b;
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
