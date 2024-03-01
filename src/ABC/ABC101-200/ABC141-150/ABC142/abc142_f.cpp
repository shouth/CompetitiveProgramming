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
using u64 = uint_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

auto g = vector<vector<i64>>();
auto seen = vector<bool>();
auto done = vector<bool>();
auto history = deque<i64>();

i64 dfs(i64 cur) {
    seen[cur] = true;
    history.emplace_front(cur);
    for (auto& e : g[cur]) {
        if (done[e]) continue;
        if (seen[e]) return e;
        if (i64 res = dfs(e); res != -1) return res;
    }
    history.pop_front();
    done[cur] = true;
    return -1;
}

void solve() {
    i64 N, M;
    cin >> N >> M;

    g.resize(N);
    for (i64 i = 0; i < M; i++) {
        i64 A, B;
        cin >> A >> B, A--, B--;
        g[A].emplace_back(B);
    }

    seen.resize(N);
    done.resize(N);
    i64 res = -1;
    for (i64 i = 0; i < N; i++) {
        res = dfs(i);
        if (res != -1) break;
    }

    if (res == -1) {
        cout << -1 << endl;
        return;
    }

    deque<i64> cycle;
    while (!history.empty()) {
        i64 t = history.front();
        cycle.emplace_front(t);
        history.pop_front();
        if (t == res) break;
    }

    while (true) {
        i64 s = cycle.size();
        vector<i64> idx(N, -1);
        for (i64 i = 0; i < s; i++) idx[cycle[i]] = i;
        i64 from = -1, to = -1;
        for (i64 i = 0; i < s; i++) {
            for (auto& e : g[cycle[i]]) {
                if (e != cycle[(i + 1) % s] && idx[e] != -1) {
                    from = i, to = idx[e];
                }
            }
        }

        if (from == -1) break;
        deque<i64> ncycle;
        ncycle.emplace_back(cycle[from]);
        for (i64 i = to; i != from; i = (i + 1) % s) {
            ncycle.emplace_back(cycle[i]);
        }
        cycle = move(ncycle);
    }

    cout << cycle.size() << "\n";
    for (auto& e : cycle) cout << e + 1 << "\n";
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
