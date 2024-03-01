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

using i64 = int_fast64_t;
using f64 = double;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;

    i64 g = __gcd(n, m);
    for (i64 si = 0, ti = 0; si < n && ti < m; si += n / g, ti += m / g) {
        if (s[si] != t[ti]) {
            cout << -1 << endl;
            return;
        }
    }
    cout << n * m / g << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
