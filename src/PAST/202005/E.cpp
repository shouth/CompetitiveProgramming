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
    i64 n, m, q;
    cin >> n >> m >> q;
    vector<vector<i64>> g(n);
    for (i64 i = 0; i < m; i++) {
        i64 u, v;
        cin >> u >> v, u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    vector<i64> cs(n);
    for (auto& e : cs) cin >> e;

    for (i64 i = 0; i < q; i++) {
        i64 c;
        cin >> c;
        if (c == 1) {
            i64 x;
            cin >> x, x--;
            cout << cs[x] << endl;
            for (auto& e : g[x]) cs[e] = cs[x];
        } else {
            i64 x, y;
            cin >> x >> y, x--;
            cout << cs[x] << endl;
            cs[x] = y;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
