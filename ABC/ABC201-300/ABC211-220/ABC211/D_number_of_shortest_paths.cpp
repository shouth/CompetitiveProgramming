#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Weverything"

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

using namespace std;
using namespace atcoder;

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;
using m64 = modint1000000007;

constexpr i64 INF = numeric_limits<i64>::max() / 2;

#pragma clang diagnostic pop

void solve()
{
    i64 N, M;
    cin >> N >> M;
    auto graph = vector<vector<i64>>(N);
    for (i64 i = 0; i < M; ++i) {
        i64 A, B;
        cin >> A >> B, --A, --B;
        graph[A].emplace_back(B);
        graph[B].emplace_back(A);
    }

    auto dist = vector<i64>(N, -1);
    dist[0] = 0;
    auto ans = vector<m64>(N);
    ans[0] = 1;
    auto q = queue<i64>();
    q.emplace(0);
    while (not q.empty()) {
        i64 cur = q.front();
        q.pop();

        for (auto &nxt : graph[cur]) {
            if (dist[nxt] == -1) {
                dist[nxt] = dist[cur] + 1;
                ans[nxt] = ans[cur];
                q.emplace(nxt);
            } else if (dist[nxt] == dist[cur] + 1) {
                ans[nxt] += ans[cur];
            }
        }
    }
    cout << ans[N - 1].val() << endl;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
