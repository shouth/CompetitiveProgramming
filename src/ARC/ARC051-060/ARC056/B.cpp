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
    i64 n, m, s;
    cin >> n >> m >> s, s--;
    vector<vector<i64>> g(n);
    for (i64 i = 0; i < m; i++) {
        i64 u, v;
        cin >> u >> v, u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    vector<i64> barrier(n, -1);
    priority_queue<p64> pq;
    pq.emplace(n, s);
    while (!pq.empty()) {
        i64 bar, cur;
        tie(bar, cur) = pq.top(); pq.pop();
        if (barrier[cur] >= bar) continue;
        barrier[cur] = bar;

        for (auto& e : g[cur]) {
            if (barrier[e] >= bar) continue;
            pq.emplace(min(cur, bar), e);
        }
    }

    for (i64 i = 0; i < n; i++) {
        if (barrier[i] > i) cout << i + 1 << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
