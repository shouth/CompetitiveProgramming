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

void solve() {
    i64 N, Q;
    cin >> N >> Q;
    auto graph = vector(N, vector<i64>());
    for (i64 i = 0; i < N - 1; ++i) {
        i64 a, b;
        cin >> a >> b, --a, --b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }

    auto dist = vector<i64>(N, -1);
    auto q = queue<i64>();
    dist[0] = 0;
    q.emplace(0);
    while (not q.empty()) {
        i64 cur = q.front();
        q.pop();

        for (auto nxt : graph[cur]) {
            if (dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            q.emplace(nxt);
        }
    }

    for (i64 i = 0; i < Q; ++i) {
        i64 c, d;
        cin >> c >> d, --c, --d;
        cout << (abs(dist[c] - dist[d]) % 2 ? "Road" : "Town") << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
