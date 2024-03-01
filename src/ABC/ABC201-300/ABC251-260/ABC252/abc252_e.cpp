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
#include <atcoder/all>

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define yes(x) ((x) ? "yes" : "no")
#define Yes(x) ((x) ? "Yes" : "No")

using namespace std;
using namespace atcoder;

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;
using m64 = modint1000000007;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 N, M;
    cin >> N >> M;
    using t64 = tuple<i64, i64, i64>;
    auto g = vector(N, vector<t64>());
    for (i64 i = 0; i < M; i++) {
        i64 A, B, C;
        cin >> A >> B >> C, A--, B--;
        g[A].emplace_back(C, B, i + 1);
        g[B].emplace_back(C, A, i + 1);
    }

    auto ways = vector<i64>(N, -1);
    auto pq = priority_queue<t64, vector<t64>, greater<>>();
    pq.emplace(0, 0, -INF);
    while (!pq.empty()) {
        auto [ cost, to, way ] = pq.top();
        pq.pop();

        if (ways[to] != -1) continue;
        ways[to] = way;

        for (auto [ dcost, next, nway ] : g[to]) {
            if (ways[next] != -1) continue;
            pq.emplace(cost + dcost, next, nway);
        }
    }

    sort(all(ways));
    ways.erase(unique(all(ways)), end(ways));
    for (i64 i = 1; i < ways.size(); i++) {
        cout << (i != 1 ? " " : "") << ways[i];
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
