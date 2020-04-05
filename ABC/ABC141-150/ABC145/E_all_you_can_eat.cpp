#include<bits/stdc++.h>
using namespace std;

using i32 = int_fast32_t;
using i64 = int_fast64_t;
using p32 = pair<i32, i32>;

int main() {
    i32 n, t;
    cin >> n >> t;
    vector<p32> ab(n);
    for (auto& e : ab) cin >> e.first >> e.second;
    sort(begin(ab), end(ab));

    vector<i32> dp(t+1);
    for (auto& e : ab) {
        i32 a, b;
        tie(a, b) = e;
        for (i32 i = t-1; i >= 0; i--) {
            dp[min(t, i+a)] = max(dp[min(t, i+a)], dp[i] + b);
        }
    }

    cout << dp[t] << endl;
}
