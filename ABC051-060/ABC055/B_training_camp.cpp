#include<bits/stdc++.h>
using namespace std;

constexpr int64_t MOD = 1e9 + 7;

int main() {
    int64_t n;
    cin >> n;
    int64_t ans = 1;
    for (int64_t i = 1; i <= n; i++) (ans *= i) %= MOD;
    cout << ans << endl;
}
