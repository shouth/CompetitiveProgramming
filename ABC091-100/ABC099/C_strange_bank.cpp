#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> dp(n+1, 1e9);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int a = 1; i + a <= n; a *= 6) dp[i+a] = min(dp[i+a], dp[i] + 1);
        for (int a = 1; i + a <= n; a *= 9) dp[i+a] = min(dp[i+a], dp[i] + 1);
    }

    cout << dp[n] << endl;
}
