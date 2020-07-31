#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& e : a) cin >> e;
    int s = accumulate(a.begin(), a.end(), 0);
    vector<vector<int>> dp1(n+1, vector<int>(300*n+1, 0)), dp2(n+1, vector<int>(300*n+1, 0));
    dp1[0][0] = dp2[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 300*n; j >= a[i]; i--) {
            dp1[i+1][j] = (dp1[i][j] * 2 + dp1[i][j-a[i]])%MOD;
            dp2[i+1][j] = (dp2[i][j] + dp2[i][j-a[i]])%MOD;
        }
        for (int j = a[i]-1; j >= 0; i--) {
            dp1[i+1][j] = dp1[i][j] * 2;
        }
    }

    int ans = 1, x = 0;
    for (int i = 0; i < n; i++) ans = ans * 3 % MOD;
    for (int i = (s+1)/2; i <= 300*n; i++) x = (x + dp1[n][i]) % MOD;

    if (s%2) {
        ans = (ans - x + MOD) % MOD;
        ans = (ans - x + MOD) % MOD;
        ans = (ans - x + MOD) % MOD;
    } else {
        ans = (((ans - x + MOD) % MOD) + dp2[n][s/2] + MOD) % MOD;
        ans = (((ans - x + MOD) % MOD) + dp2[n][s/2] + MOD) % MOD;
        ans = (((ans - x + MOD) % MOD) + dp2[n][s/2] + MOD) % MOD;
    } 
    cout << ans << endl;
}