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

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

void solve() {
    i64 n;
    cin >> n;
    vector<p64> a(n);
    for (i64 i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(begin(a), end(a), greater());

    vector<vector<i64>> dp(n + 1, vector<i64>(n + 1));
    for (i64 i = 0; i < n; i++) {
        const auto& [ e, p ] = a[i];
        for (i64 j = 0; j <= i; j++) {
            dp[j+1][i-j] = max(dp[j+1][i-j], e * abs(p-j) + dp[j][i-j]);
            dp[j][i-j+1] = max(dp[j][i-j+1], e * abs(p-(n-1-(i-j))) + dp[j][i-j]);
        }
    }

    i64 ans = 0;
    for (i64 i = 0; i <= n; i++) ans = max(ans, dp[i][n-i]);
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
