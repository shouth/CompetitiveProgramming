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
using m64 = modint998244353;

constexpr i64 INF = numeric_limits<i64>::max() / 2;

#pragma clang diagnostic pop

void solve()
{
    i64 N, M, K;
    cin >> N >> M >> K;

    auto broken = vector<vector<i64>>(N);
    for (i64 i = 0; i < M; ++i) {
        i64 U, V;
        cin >> U >> V, --U, --V;
        broken[U].emplace_back(V);
        broken[V].emplace_back(U);
    }

    auto dp = vector(2, vector<m64>(N));
    dp[0][0] = 1;
    for (i64 i = 0; i < K; ++i) {
        auto &cur = dp[i % 2];
        auto &nxt = dp[(i + 1) % 2];

        auto sum = reduce(begin(cur), end(cur));
        for (i64 j = 0; j < N; ++j) {
            auto tmp = transform_reduce(begin(broken[j]), end(broken[j]),
                m64(0), plus(), [&](i64 x) { return cur[x]; });
            nxt[j] = sum - tmp - cur[j];
        }
    }
    cout << dp[K % 2][0].val() << endl;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
