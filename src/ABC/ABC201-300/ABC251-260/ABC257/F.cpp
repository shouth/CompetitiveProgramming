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
    auto g = vector(N + 1, vector<i64>());
    for (i64 i = 0; i < M; i++) {
        i64 U, V;
        cin >> U >> V;
        g[U].emplace_back(V);
        g[V].emplace_back(U);
    }

    auto f = [&](i64 start) {
        auto q = queue<i64>();
        auto dist = vector<i64>(N + 1, INF);
        dist[start] = 0;
        q.emplace(start);
        while (!q.empty()) {
            i64 t = q.front();
            q.pop();

            for (auto &e : g[t]) {
                if (dist[e] < INF) continue;
                dist[e] = dist[t] + 1;
                q.emplace(e);
            }
        }
        return dist;
    };
    auto dist1 = f(1);
    auto distN = f(N);

    for (i64 i = 1; i <= N; i++) {
        i64 ans = min(dist1[N], min(dist1[0], dist1[i]) + min(distN[0], distN[i]));
        cout << (i == 1 ? "" : " ") << (ans < INF ? ans : -1);
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
