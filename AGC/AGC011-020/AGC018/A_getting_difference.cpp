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
    i64 n, k;
    cin >> n >> k;
    vector<i64> a(n);
    for (auto& e : a) cin >> e;

    if (*max_element(all(a)) < k) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    i64 d = accumulate(all(a), 0l, __gcd<i64>);
    if (d == 1) {
        cout << "POSSIBLE" << endl;
        return;
    }

    if (__gcd(d, k) == 1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    cout << "POSSIBLE" << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
