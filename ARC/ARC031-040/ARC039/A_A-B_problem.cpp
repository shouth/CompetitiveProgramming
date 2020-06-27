#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 a, b;
    cin >> a >> b;
    i64 na =
        a / 100 != 9 ? a % 100 + 900
        : a / 10 % 10 != 9 ? a / 100 * 100 + 90 + a % 10
        : a / 10 * 10 + 9;
    i64 nb =
        b / 100 != 1 ? b % 100 + 100
        : b / 10 % 10 != 0 ? b / 100 * 100 + b % 10
        : b / 10 * 10;
    cout << max(a - nb, na - b) << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
