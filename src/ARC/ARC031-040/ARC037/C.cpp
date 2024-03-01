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
    i64 n, k;
    cin >> n >> k;
    vector<i64> a(n), b(n);
    for (auto& e : a) cin >> e;
    for (auto& e : b) cin >> e;
    sort(all(a));
    sort(all(b));

    i64 l = -1, r = INF;
    while (abs(r - l) > 1) {
        i64 m = (l + r) / 2;

        i64 cnt = 0;
        for (auto& e : a) cnt += upper_bound(all(b), m / e) - begin(b);
        (cnt < k ? l : r) = m;
    }

    cout << r << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
