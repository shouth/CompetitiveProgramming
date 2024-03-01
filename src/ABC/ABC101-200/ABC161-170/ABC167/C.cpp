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

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 n, m, x;
    cin >> n >> m >> x;
    vector<i64> c(n);
    vector<vector<i64>> a(n, vector<i64>(m));
    for (i64 i = 0; i < n; i++) {
        cin >> c[i];
        for (auto& e : a[i]) cin >> e;
    }

    i64 ans = INF;
    for (i64 i = 0; i < (1l << n); i++) {
        i64 can = 0;
        vector<i64> u(m);
        for (i64 j = 0; j < n; j++) {
            if ((i >> j) & 1) continue;
            can += c[j];
            for (i64 k = 0; k < m; k++) u[k] += a[j][k];
        }
        if (all_of(all(u), [&](i64 t) { return t >= x; })) ans = min(ans, can);
    }
    cout << (ans != INF ? ans : -1) << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
