#include<bits/stdc++.h>
using namespace std;

using i64 = int_fast64_t;
using f64 = double;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 s;
    cin >> s;

    constexpr i64 e = 1e9;
    if (s == e * e) {
        cout << 0 << " " << 0 << " ";
        cout << e << " " << 0 << " ";
        cout << 0 << " " << e << endl;
    } else {
        i64 x = e - s % e;
        i64 y = (s + x) / e;
        cout << 0 << " " << 0 << " ";
        cout << e << " " << 1 << " ";
        cout << x << " " << y << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
