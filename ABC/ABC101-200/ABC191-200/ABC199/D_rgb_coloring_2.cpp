#include<bits/stdc++.h>
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
    i64 N, M;
    cin >> N >> M;
    auto graph = vector<vector<i64>>(N);
    auto edges = vector<p64>(M);
    for (auto &[ A, B ] : edges) {
        cin >> A >> B, A--, B--;
        graph[A].emplace_back(B);
        graph[B].emplace_back(A);
    }

    auto visited = vector<i64>(N);
    i64 ans = 1;
    for (i64 i = 0; i < N; i++) {
        if (visited[i]) continue;

        auto s = vector<p64>();
        auto q = queue<p64>();
        q.emplace(i, -1);
        while (!q.empty()) {
            auto [ t, from ] = q.front();
            q.pop();

            if (visited[t]) continue;
            visited[t] = true;
            s.emplace_back(t, from);
            for (auto &e : graph[t]) {
                if (visited[e]) continue;
                q.emplace(e, t);
            }
        }

        auto color = vector<i64>(N);
        color[i] = 1;
        auto f = [&](const auto &rec, i64 depth) -> i64 {
            if (depth == (i64) s.size()) {
                for (auto [ from, to ] : edges) {
                    if (color[from] && color[to] && color[from] == color[to]) return 0;
                }
                return 1;
            } else {
                i64 res = 0;
                for (i64 c = 1; c <= 3; c++) {
                    auto [ n, from ] = s[depth];
                    if (color[from] == c) continue;
                    color[n] = c;
                    res += rec(rec, depth + 1);
                }
                return res;
            }
        };
        ans *= f(f, 1) * 3;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
