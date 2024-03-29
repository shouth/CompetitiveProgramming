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

    auto graph = vector(N, vector<i64>());
    for (i64 i = 0; i < M; ++i) {
        i64 A, B;
        cin >> A >> B, --A, --B;
        graph[A].emplace_back(B);
    }

    i64 ans = 0;
    for (i64 i = 0; i < N; ++i) {
        auto visited = vector<bool>(N);
        auto q = queue<i64>();
        visited[i] = 1;
        q.emplace(i);
        ++ans;
        while (not q.empty()) {
            i64 n = q.front();
            q.pop();

            for (auto &m : graph[n]) {
                if (visited[m]) continue;
                visited[m] = 1;
                q.emplace(m);
                ++ans;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
