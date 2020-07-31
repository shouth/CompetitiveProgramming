#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 n;
    cin >> n;
    i64 a, b;
    cin >> a >> b;
    i64 x = 0, y = 0, z = 0;
    for (i64 i = 0; i < n; i++) {
        i64 p;
        cin >> p;
        (p <= a ? x : p <= b ? y : z)++;
    }
    cout << min({ x, y, z }) << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
