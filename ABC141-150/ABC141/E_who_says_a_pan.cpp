#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 0;
    for (int len = 1; len <= n; len++) {
        vector<map<string, int>> dp(n, map<string, int>());
        dp[len - 1][s.substr(0, len)]++;
        // cout << s.substr(0, len) << endl;
        for (int i = len; i < n; i++) {
            for (auto& e : dp[i-1]) dp[i][e.first] = e.second;
            // cout << s.substr(i-len+1, len) << " ";
            dp[i][s.substr(i-len+1, len)] = max(dp[i-len][s.substr(i-len+1, len)] + 1, dp[i][s.substr(i-len+1, len)]);
            // cout << dp[i][s.substr(i-len+1, len)] << " " << i-len << endl;
            if (dp[i][s.substr(i-len+1, len)] == 2) ans = len;
        }
    }

    cout << ans << endl;
}
