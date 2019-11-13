#include<bits/stdc++.h>
using namespace std;

constexpr int64_t MOD = 1e9 + 7;

int main() {
    string s;
    cin >> s;
    vector<vector<int64_t>> dp(s.size() + 1, vector<int64_t>(4));
    dp[s.size()][3] = 1;
    for (int i = s.size() - 1; i >= 0; i--) {
        dp[i][3] = dp[i+1][3] * (s[i] == '?' ? 3 : 1) % MOD;
        for (int j = 2; j >= 0; j--) {
            dp[i][j] = (dp[i+1][j] * (s[i] == '?' ? 3 : 1)
                + dp[i+1][j+1] * (s[i] == '?' || s[i] == ('A' + j) ? 1 : 0)) % MOD;
        }
    }

    cout << dp[0][0] << endl;
}
