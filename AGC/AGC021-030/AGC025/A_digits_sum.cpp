#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using f64 = double;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 n;
    cin >> n;

    i64 ans = INF;
    for (i64 i = 1; i < n; i++) {
        i64 can = 0;
        for (auto e : { i, n - i }) {
            while (e) can += e % 10, e /= 10;
        }
        ans = min(ans, can);
    }

    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
