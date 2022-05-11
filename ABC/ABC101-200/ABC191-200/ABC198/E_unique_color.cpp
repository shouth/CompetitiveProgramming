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
#define yes(x) ((x) ? "yes" : "no")
#define Yes(x) ((x) ? "Yes" : "No")

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 N;
    cin >> N;
    auto C = vector<i64>(N);
    for (auto &e : C) cin >> e, e--;
    auto tree = vector<vector<i64>>(N);
    for (i64 i = 0; i < N - 1; i++) {
        i64 A, B;
        cin >> A >> B, A--, B--;
        tree[A].push_back(B);
        tree[B].push_back(A);
    }

    auto colored = vector<i64>(*max_element(all(C)) + 1);
    auto visited = vector<i64>(N);
    auto ans = vector<i64>();
    auto dfs = [&](auto &rec, i64 node) -> void {
        visited[node] = 1;
        if (!colored[C[node]]) ans.emplace_back(node);
        colored[C[node]]++;
        for (const auto &e : tree[node]) {
            if (visited[e]) continue;
            rec(rec, e);
        }
        colored[C[node]]--;
    };
    dfs(dfs, 0);
    sort(all(ans));
    for (const auto &e : ans) cout << e + 1 << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
