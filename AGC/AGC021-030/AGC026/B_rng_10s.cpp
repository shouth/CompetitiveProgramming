#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using f64 = double;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 t;
    cin >> t;

    for (i64 i = 0; i < t; i++) {
        i64 a, b, c, d;
        cin >> a >> b >> c >> d;

        if (a < b) {
            cout << "No" << endl;
            continue;
        }

        if (d < b) {
            cout << "No" << endl;
            continue;
        }

        if (b < c) {
            cout << "Yes" << endl;
            continue;
        }

        i64 g = __gcd(b, d);
        if (b - g + (a % g) > c) {
            cout << "No" << endl;
            continue;
        }

        cout << "Yes" << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
