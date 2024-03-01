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
    i64 k;
    cin >> k;
    vector<i64> a(k);
    for (auto& e : a) cin >> e;
    reverse(all(a));

    i64 nmin = 2, nmax = 2;
    for (auto& e : a) {
        nmin = (nmin + e - 1) / e * e, nmax = nmax / e * e + e - 1;
        if (nmin > nmax) {
            cout << -1 << endl;
            return;
        }
    }

    cout << nmin << " " << nmax << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
