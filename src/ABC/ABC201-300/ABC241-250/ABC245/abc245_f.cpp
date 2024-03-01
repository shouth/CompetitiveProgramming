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

#include<atcoder/all>

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
    auto rev = vector(N, vector<i64>());
    auto scc = scc_graph((int) N);
    for (i64 i = 0; i < M; i++) {
        i64 U, V;
        cin >> U >> V, U--, V--;
        rev[V].emplace_back(U);
        scc.add_edge((int) U, (int) V);
    }

    auto g = scc.scc();
    auto q = queue<i64>();
    for (auto &e : g) {
        if (e.size() == 1) continue;
        for (auto &f : e) {
            q.emplace(f);
        }
    }

    auto visited = vector<i64>(N);
    while (!q.empty()) {
        i64 t = q.front();
        q.pop();

        if (visited[t]) continue;
        visited[t] = 1;

        for (auto &e : rev[t]) {
            if (visited[e]) continue;
            q.emplace(e);
        }
    }
    cout << reduce(all(visited)) << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
