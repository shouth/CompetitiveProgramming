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

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 N, M;
    cin >> N >> M;
    vector<i64> A(N), B(M);
    for (auto& e : A) cin >> e;
    for (auto& e : B) cin >> e;

    auto dp = vector(N, vector(M, i64(-1)));
    auto dfs = [&](auto f, i64 i, i64 j) -> i64 {
        if (i < 0 && j < 0) return 0;
        if (i < 0) return j + 1;
        if (j < 0) return i + 1;
        if (dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = min({
            f(f, i - 1, j - 1) + (A[i] != B[j]),
            f(f, i - 1, j) + 1,
            f(f, i, j - 1) + 1,
        });
    };

    cout << dfs(dfs, N - 1, M - 1) << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
