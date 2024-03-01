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
    i64 n, m;
    cin >> n >> m;
    vector<vector<i64>> g(n);
    for (i64 i = 0; i < m; i++) {
        i64 a, b;
        cin >> a >> b, a--, b--;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    i64 ans = 0;
    vector<i64> used(n);
    for (i64 i = 0; i < n; i++) {
        if (used[i]) continue;
        ans++;

        queue<i64> q;
        q.emplace(i);
        while (!q.empty()) {
            i64 t = q.front(); q.pop();
            used[t] = 1;
            for (auto& e : g[t]) {
                if (!used[e]) q.emplace(e);
            }
        }
    }
    cout << ans - 1 << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
