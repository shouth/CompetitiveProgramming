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

using namespace std;
using namespace atcoder;

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;
using m64 = modint1000000007;

constexpr i64 INF = numeric_limits<i64>::max() / 2;

void solve() {
    i64 N, M;
    cin >> N >> M;
    auto adj = vector(N, vector<i64>(N, INF));
    for (i64 i = 0; i < M; ++i) {
        i64 A, B, C;
        cin >> A >> B >> C, --A, --B;
        adj[A][B] = C;
    }

    for (i64 i = 0; i < N; ++i) {
        adj[i][i] = 0;
    }

    i64 ans = 0;
    for (i64 k = 0; k < N; ++k) {
        for (i64 s = 0; s < N; ++s) {
            for (i64 t = 0; t < N; ++t) {
                if ((adj[s][t] = min(adj[s][t], adj[s][k] + adj[k][t])) < INF) {
                    ans += adj[s][t];
                }
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
