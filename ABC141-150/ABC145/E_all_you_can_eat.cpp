#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t n, t;
    cin >> n >> t;
    using pint = pair<int64_t, int64_t>;
    vector<pint> ab(n);
    for (auto& e : ab) cin >> e.first >> e.second;

    int64_t ans = 0;
    vector<vector<pint>> dp(n+1, vector<pint>(6010));
    for (int64_t i = 0; i < n; i++) {
        for (int64_t j = 0; j < 6010; j++) {
            if (j - ab[i].first < 0) {
                dp[i+1][j] = dp[i][j];
            } else {
                if (dp[i][j].first < dp[i][j-ab[i].first].first + ab[i].second) {
                    dp[i+1][j] = make_pair(dp[i][j-ab[i].first].first + ab[i].second, j-ab[i].first);
                    if (dp[i+1][j].second < t) ans = max(ans, dp[i+1][j].first);
                } else {
                    dp[i+1][j] = dp[i][j];
                }
            }
        }
    }

    cout << ans << endl;
}
