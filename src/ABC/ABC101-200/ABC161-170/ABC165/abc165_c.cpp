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

vector<i64> v;
i64 n, m, q;
vector<i64> a, b, c, d;

i64 dfs(i64 depth, i64 pre) {
    i64 res = 0;
    if (depth == n) {
        for (i64 i = 0; i < q; i++) {
            if (v[b[i]] - v[a[i]] == c[i]) res += d[i];
        }
    } else {
        for (i64 i = pre; i < m; i++) {
            v.push_back(i);
            res = max(res, dfs(depth + 1, i));
            v.pop_back();
        }
    }
    return res;
}

void solve() {
    cin >> n >> m >> q;
    a.assign(q, 0), b.assign(q, 0), c.assign(q, 0), d.assign(q, 0);
    for (i64 i = 0; i < q; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
    cout << dfs(0, 0) << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
