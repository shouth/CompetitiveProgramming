#include<bits/stdc++.h>
using namespace std;

constexpr int64_t MOD = 1e9+7;

int main() {
    int n;
    cin >> n;
    vector<string> s(2);
    cin >> s[0] >> s[1];
    vector<int64_t> dp(n);
    dp[0] = s[0][0] == s[1][0] ? 3 : 6;
    for (int64_t i = 0; i+1 < n; i++) {
        if (s[0][i] == s[0][i+1]) dp[i+1] = dp[i];
        else if (s[0][i] == s[1][i]) dp[i+1] = dp[i] * 2 % MOD;
        else if (s[0][i+1] == s[1][i+1]) dp[i+1] = dp[i];
        else dp[i+1] = dp[i] * 3 % MOD;
    }
    cout << dp.back() << endl;
}
