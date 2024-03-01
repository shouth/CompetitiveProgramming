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
    i64 a, b, c;
    cin >> a >> b >> c;

    if (a % 2 == 0 && a == b && b == c && c == a) {
        cout << -1 << endl;
        return;
    }

    i64 ans = 0;
    while (a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
        i64 na = (b + c) / 2;
        i64 nb = (c + a) / 2;
        i64 nc = (a + b) / 2;
        a = na, b = nb, c = nc;
        ans++;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
