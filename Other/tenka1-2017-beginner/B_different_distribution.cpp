#include<bits/stdc++.h>
using namespace std;

using i64 = int_fast64_t;
using f64 = double;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 n;
    cin >> n;
    i64 ans0 = INF, ans1 = INF;
    for (i64 i = 0; i < n; i++) {
        i64 a, b;
        cin >> a >> b;
        if (b < ans1) ans0 = a, ans1 = b;
    }

    cout << ans0 + ans1 << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
