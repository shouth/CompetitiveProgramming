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
    auto D = vector<i64>(N);
    for (auto &e : D) cin >> e;
    auto g = vector<vector<i64>>(N);
    for (i64 i = 0; i < M; i++) {
        i64 A, B;
        cin >> A >> B, A--, B--;
        g[A].emplace_back(B);
        g[B].emplace_back(A);
    }

    if (reduce(all(D)) != 2 * (N - 1)) {
        cout << -1 << endl;
        return;
    }

    auto build = vector<deque<i64>>();
    auto visited = vector<bool>(N);
    auto q = deque<i64>();
    for (i64 i = 0; i < N; i++) {
        if (visited[i]) continue;
        visited[i] = 1;
        q.emplace_back(i);

        auto &sub = build.emplace_back();
        while (!q.empty()) {
            i64 t = q.front();
            q.pop_front();

            i64 cnt = D[t] - g[t].size();
            if (cnt < 0) {
                cout << -1 << endl;
                return;
            }
            sub.insert(sub.end(), cnt, t);

            for (i64 n : g[t]) {
                if (visited[n]) continue;
                visited[n] = 1;
                q.emplace_back(n);
            }
        }
    }

    auto ord = vector<i64>(build.size());
    iota(all(ord), 0);
    sort(all(ord), [&](i64 a, i64 b) { return build[a].size() > build[b].size(); });

    q.insert(q.end(), make_move_iterator(build[ord[0]].begin()), make_move_iterator(build[ord[0]].end()));
    auto ans = vector<p64>();
    for (i64 i = 1; i < build.size(); i++) {
        if (q.empty() || build[ord[i]].empty()) {
            cout << -1 << endl;
            return;
        }
        ans.emplace_back(q.front(), build[ord[i]].front());
        q.pop_front();
        build[ord[i]].pop_front();
        q.insert(q.end(), make_move_iterator(build[ord[i]].begin()), make_move_iterator(build[ord[i]].end()));
    }

    if (!q.empty()) {
        cout << -1 << endl;
        return;
    }

    for (auto [ a, b ] : ans) {
        cout << a + 1 << " " << b + 1 << "\n";
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
