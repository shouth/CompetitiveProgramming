#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define yes(x) ((x) ? "yes" : "no")
#define Yes(x) ((x) ? "Yes" : "No")

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 N;
    cin >> N;
    double x, y;
    cin >> x >> y;
    complex origin(x, y);
    cin >> x >> y;
    complex opposite(x, y);

    complex center = (origin + opposite) / 2.0;
    complex ans = (origin - center) * polar(1.0, 2.0 * M_PI / (double) N) + center;
    cout << ans.real() << " " << ans.imag() << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
