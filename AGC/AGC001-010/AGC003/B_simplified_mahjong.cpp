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
    i64 sum = 0, tmp = 0;
    for (i64 i = 0; i < n; i++) {
        i64 a;
        cin >> a;
        if (a) tmp += a; else sum += tmp / 2, tmp = 0;
    }
    cout << sum + tmp / 2 << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
