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
    i64 N;
    cin >> N;
    auto C = vector<i64>(9);
    for (auto &e : C) cin >> e;

    auto dp = vector<i64>(N + 1);
    for (i64 i = 0; i < N; i++) {
        for (auto e : C) {
            i64 ni = i + e;
            if (ni <= N) dp[ni] = max(dp[ni], dp[i] + 1);
        }
    }

    i64 cost = N;
    while (dp[cost] > 0) {
        for (i64 i = 8; i >= 0; i--) {
            i64 ncost = cost - C[i];
            if (ncost >= 0 && dp[cost] == dp[ncost] + 1) {
                cout << i + 1;
                cost = ncost;
                break;
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
