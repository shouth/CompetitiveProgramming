#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 a, r, n;
    cin >> a >> r >> n;

    if (log10(a) + log10(r) * (f64) (n - 1) > 9) {
        cout << "large" << endl;
    } else {
        cout << a * (i64) pow(r, n - 1) << endl;
    }

}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
