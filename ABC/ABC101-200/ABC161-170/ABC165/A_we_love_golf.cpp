#include<bits/stdc++.h>
using namespace std;

using i64 = int_fast64_t;
using f64 = double;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 k, a, b;
    cin >> k >> a >> b;
    string ans = "NG";
    for (i64 i = 0; i * k <= b; i++) {
        if (a <= i * k && i * k <= b) ans = "OK";
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
