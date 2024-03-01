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
    i64 r, b;
    cin >> r >> b;
    i64 x, y;
    cin >> x >> y;

    i64 bottom = 0, top = INF;
    while (abs(top - bottom) > 1) {
        i64 m = (top + bottom) / 2;
        i64 n = (r - m) / (x - 1) + (b - m) / (y - 1);
        (n < m || r < m || b < m ? top : bottom) = m;
    }
    cout << bottom << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
