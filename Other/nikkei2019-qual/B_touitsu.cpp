#include<bits/stdc++.h>
using namespace std;

using i64 = int_fast64_t;
using f64 = double;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 n;
    cin >> n;
    string a, b, c;
    cin >> a >> b >> c;

    i64 ans = 0;
    for (i64 i = 0; i < n; i++) {
        switch ((a[i] == b[i]) + (b[i] == c[i]) + (c[i] == a[i])) {
        case 0:
            ans += 2;
            break;
        case 1:
            ans += 1;
            break;
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
