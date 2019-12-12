#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& e : a) cin >> e;
    vector<int> dp(n, 1e9);
    dp[0] = 0;
    for (int i = 0; i+1 < n; i++) {
        dp[i+1] = min(dp[i+1], dp[i] + abs(a[i]-a[i+1]));
        if (i+2 < n) dp[i+2] = min(dp[i+2], dp[i] + abs(a[i]-a[i+2]));
    }

    cout << dp.back() << endl;
}
