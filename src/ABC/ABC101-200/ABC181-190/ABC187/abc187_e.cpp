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
#define rall(x) rbegin(x), rend(x)

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 N;
    cin >> N;

    vector<vector<i64>> g(N);
    vector<i64> as(N - 1), bs(N - 1);

    for (i64 i = 0; i < N - 1; i++) {
        cin >> as[i] >> bs[i], as[i]--, bs[i]--;
        g[as[i]].emplace_back(bs[i]);
        g[bs[i]].emplace_back(as[i]);
    }

    auto depth = vector<i64>(N, -1);

    queue<i64> nxt;
    nxt.push(0);
    depth[0] = 0;
    while (!nxt.empty()) {
        i64 t = nxt.front();
        nxt.pop();

        for (auto& e : g[t]) {
            if (depth[e] != -1) continue;
            depth[e] = depth[t] + 1;
            nxt.push(e);
        }
    }

    i64 Q;
    cin >> Q;

    auto ans = vector<i64>(N);
    for (i64 i = 0; i < Q; i++) {
        i64 t, e, x;
        cin >> t >> e >> x, e--;

        i64 ai = as[e], bi = bs[e];
        if (t == 2) swap(ai, bi);
        if (depth[ai] > depth[bi]) {
            ans[ai] += x;
        } else {
            ans[0] += x;
            ans[bi] -= x;
        }
    }

    nxt.push(0);
    while (!nxt.empty()) {
        i64 t = nxt.front();
        nxt.pop();

        for (auto& e : g[t]) {
            if (depth[e] <= depth[t]) continue;
            ans[e] += ans[t];
            nxt.push(e);
        }
    }

    for (auto& e : ans) cout << e << "\n";
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
