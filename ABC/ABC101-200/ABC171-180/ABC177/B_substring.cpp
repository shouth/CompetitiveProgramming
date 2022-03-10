#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    string S, T;
    cin >> S >> T;
    i64 n = S.size(), m = T.size();
    i64 ans = INF;
    for (i64 i = 0; i + m <= n; i++) {
        i64 tmp = 0;
        for (i64 j = 0; j < m; j++) {
            if (S[i + j] != T[j]) tmp++;
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
