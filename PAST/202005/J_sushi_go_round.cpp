#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 n, m;
    cin >> n >> m;

    vector<i64> eat(n);
    for (i64 i = 0; i < m; i++) {
        i64 a;
        cin >> a;
        i64 idx = upper_bound(all(eat), a, greater()) - begin(eat);
        if (idx == n) {
            cout << -1 << endl;
        } else {
            eat[idx] = a;
            cout << idx + 1 << endl;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
