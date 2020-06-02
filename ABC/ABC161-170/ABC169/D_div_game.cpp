#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 n;
    cin >> n;

    map<i64, i64> factor;
    for (i64 i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factor[i]++;
            n /= i;
        }
    }
    if (n != 1) factor[n] = 1;

    i64 ans = 0;
    for (auto& e : factor) {
        i64 num, cnt;
        tie(num, cnt) = e;
        for (i64 i = 1; cnt - i >= 0; i++) {
            cnt -= i;
            ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
