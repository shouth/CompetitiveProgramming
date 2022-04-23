#include<bits/stdc++.h>
#include<atcoder/all>

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define yes(x) ((x) ? "yes" : "no")
#define Yes(x) ((x) ? "Yes" : "No")

using namespace std;
using namespace atcoder;

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;
using m64 = modint1000000007;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    auto x = vector<i64>(3);
    auto y = vector<i64>(3);
    for (i64 i = 0; i < 3; i++) cin >> x[i] >> y[i];

    if (x[0] == x[1]) {
        cout << x[2];
    } else if (x[1] == x[2]) {
        cout << x[0];
    } else {
        cout << x[1];
    }
    cout << " ";

    if (y[0] == y[1]) {
        cout << y[2];
    } else if (y[1] == y[2]) {
        cout << y[0];
    } else {
        cout << y[1];
    }
    cout << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
