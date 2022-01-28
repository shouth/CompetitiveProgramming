#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define yes(x) ((x) ? "yes" : "no")
#define Yes(x) ((x) ? "Yes" : "No")

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

i64 c(i64 n, i64 k) {
    if (k < 0 || n < k) return 0;
    if (n - k < k) k = n - k;
    i64 res = 1;
    for (i64 i = 1; i <= k; i++) res = res * (n - i + 1) / i;
    return res;
}

void solve() {
    i64 P;
    cin >> P;

    double win = P / 100.0;
    double lose = 1 - win;

    double ans =
        c(7, 4) * std::pow(win, 4) * std::pow(lose, 3)
        + c(7, 5) * std::pow(win, 5) * std::pow(lose, 2)
        + c(7, 6) * std::pow(win, 6) * std::pow(lose, 1)
        + c(7, 7) * std::pow(win, 7) * std::pow(lose, 0);
    cout << ans * 100 << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
