#include<bits/stdc++.h>
using namespace std;

using i64 = int_fast64_t;
using f64 = double;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 n, m;
    cin >> n >> m;
    i64 l = 1, r = 1 + m;
    for (i64 i = 0; i < m; i++) {
        cout << l << " " << r << endl;
        if (i % 2 == 0) {
            l += m, r += m, l++;
        } else {
            l -= m, r -= m, r--;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
