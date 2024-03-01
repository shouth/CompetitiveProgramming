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
using p64 = pair<i64, i64>;
using t64 = tuple<i64, i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 n, m, s;
    cin >> n >> m >> s;
    vector<vector<t64>> g(n);
    i64 lim = 0;
    for (i64 i = 0; i < m; i++) {
        i64 u, v, a, b;
        cin >> u >> v >> a >> b, u--, v--;
        g[u].emplace_back(v, a, b);
        g[v].emplace_back(u, a, b);
        lim += a;
    }
    for (i64 i = 0; i < n; i++) {
        i64 c, d;
        cin >> c >> d;
        g[i].emplace_back(i, -c, d);
    }

    priority_queue<t64, vector<t64>, greater<>> pq;
    pq.emplace(0, 0, s);
    map<p64, i64> t;
    t[{0, s}] = 0;

    vector<i64> ans(n, -1);
    i64 u = n;
    while (!pq.empty()) {
        i64 time, town, coin;
        tie(time, town, coin) = pq.top(); pq.pop();

        if (ans[town] == -1) {
            ans[town] = time;
            u--;
            if (u == 0) break;
        }

        for (auto& e : g[town]) {
            i64 to, cost, wait;
            tie(to, cost, wait) = e;
            i64 ncoin = coin - cost, ntime = time + wait;
            if (ncoin < 0 || (ncoin > coin && ncoin > lim && coin > lim)) continue;
            if (t.find({to, ncoin}) != t.end() && t[{to, ncoin}] <= ntime) continue;
            t[{to, ncoin}] = ntime;
            pq.emplace(ntime, to, ncoin);
        }
    }

    for (i64 i = 1; i < n; i++) cout << ans[i] << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
