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
    i64 n, a, b;
    cin >> n >> a >> b;
    vector<i64> s(n);
    for (auto& e : s) cin >> e;
    i64 maxs = *max_element(all(s));
    i64 mins = *min_element(all(s));

    i64 d = maxs - mins;
    if (d == 0) {
        cout << -1 << endl;
        return;
    }

    f64 p = (f64) b / (f64) d;
    f64 avg = accumulate(all(s), 0.0) / (f64) n;
    f64 q = (f64) a - p * avg;
    cout << p << " " << q << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
