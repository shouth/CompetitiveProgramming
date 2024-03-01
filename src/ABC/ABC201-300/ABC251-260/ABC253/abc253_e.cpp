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
using m64 = modint998244353;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 N, M, K;
    cin >> N >> M >> K;

    m64 ans;
    if (K == 0) {
        ans = m64(M).pow(N);
    } else {
        auto dp = vector<m64>(M + 1);
        auto predp = vector<m64>(M + 1);
        fill(dp.begin() + 1, dp.end(), 1);
        for (i64 i = 1; i < N; ++i) {
            swap(dp, predp);
            inclusive_scan(all(predp), begin(predp));
            for (i64 a = 1; a <= M; ++a) {
                i64 top = min<i64>(M, a + K - 1);
                i64 bottom = max<i64>(0, a - K);
                dp[a] = predp.back() - (predp[top] - predp[bottom]);
            }
        }
        ans = reduce(all(dp));
    }
    cout << ans.val() << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
