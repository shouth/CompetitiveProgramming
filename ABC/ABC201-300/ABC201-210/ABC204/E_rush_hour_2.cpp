#pragma clang diagnostic ignored "-Wunused-variable"
#pragma clang diagnostic ignored "-Wunused-const-variable"

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

constexpr i64 INF = std::numeric_limits<i64>::max() / 2;

void solve() {
    i64 N, M;
    cin >> N >> M;
    auto graph = vector(N, vector<tuple<i64, i64, i64>>());
    for (i64 i = 0; i < M; ++i) {
        i64 A, B, C, D;
        cin >> A >> B >> C >> D, --A, --B;
        graph[A].emplace_back(B, C, D);
        graph[B].emplace_back(A, C, D);
    }

    auto ans = vector<i64>(N, -1);
    auto pq = priority_queue<p64, vector<p64>, greater<>>();
    pq.emplace(0, 0);
    while (not pq.empty()) {
        auto [ time, to ] = pq.top();
        pq.pop();

        if (ans[to] != -1) continue;
        ans[to] = time;

        for (auto &[ nxt, C, D ] : graph[to]) {
            if (ans[nxt] != -1) continue;
            i64 wait = round(sqrt(D)) - 1;
            i64 ntime = time <= wait ? wait : time;
            pq.emplace(ntime + C + floor(D / (ntime + 1)), nxt);
        }
    }
    cout << ans.back() << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
