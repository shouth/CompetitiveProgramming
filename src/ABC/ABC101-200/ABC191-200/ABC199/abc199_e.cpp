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
    i64 N, M;
    cin >> N >> M;
    auto cs = vector<vector<p64>>(N + 1);
    for (i64 i = 0; i < M; i++) {
        i64 X, Y, Z;
        cin >> X >> Y >> Z;
        cs[X].emplace_back(Y, Z);
    }

    auto dp = vector<i64>(1ll << N);
    dp[0] = 1;
    for (i64 a = 1; a < (1ll << N); a++) {
        bool flag = true;
        for (auto [ Y, Z ] : cs[__builtin_popcountll(a)]) {
            flag &= __builtin_popcountll(a & ((1ll << Y) - 1)) <= Z;
        }
        if (!flag) continue;
        for (i64 i = 0; i < N; i++) {
            if ((a >> i) & 1) dp[a] += dp[a ^ (1ll << i)];
        }
    }
    cout << dp.back() << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
