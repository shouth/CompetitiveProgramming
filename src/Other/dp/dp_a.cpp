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

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 n;
    cin >> n;
    vector<i64> h(n);
    for (auto& e : h) cin >> e;

    vector<i64> dp(n, INF);
    dp[0] = 0;
    for (i64 i = 0; i + 1 < n; i++) {
        dp[i + 1] = min(dp[i + 1], dp[i] + abs(h[i + 1] - h[i]));
        if (i + 2 < n) dp[i + 2] = min(dp[i + 2], dp[i] + abs(h[i + 2] - h[i]));
    }
    cout << dp[n - 1] << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
