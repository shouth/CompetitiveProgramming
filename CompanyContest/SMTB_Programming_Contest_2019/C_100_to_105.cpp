#include<bits/stdc++.h>
using namespace std;

int main() {
    int x;
    cin >> x;
    vector<int> dp(100001);
    dp[0] = 1;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j <= 100000; j++) {
            if (j-(100+i) >= 0) dp[j] |= dp[j-(100+i)];
        }
    }

    cout << dp[x] << endl;
}
