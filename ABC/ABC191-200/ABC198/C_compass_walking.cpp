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
    i64 R, X, Y;
    cin >> R >> X >> Y;

    i64 l = 0, r = 1e6;
    while (r - l > 1) {
        i64 m = (r - l) / 2 + l;
        (m * R < (i64) 1e6 && (m * R) * (m * R) < X * X + Y * Y ? l : r) = m;
    }
    cout << (r == 1 && R * R != X * X + Y * Y ? 2 : r) << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
