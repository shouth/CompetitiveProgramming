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
    vector<vector<char>> ss(2 * n, vector<char>(2 * n));
    for (i64 i = 0; i < n; i++) {
        for (i64 j = 0; j < n; j++) {
            cin >> ss[i][j];
            ss[i + n][j] = ss[i][j + n] = ss[i + n][j + n] = ss[i][j];
        }
    }

    i64 ans = 0;
    for (i64 i = 0; i <= 2 * n - 2; i++) {
        i64 ay = min(i, n - 1), ax = min(2 * n - 2 - i, n - 1);

        i64 err = 0;
        for (i64 ry = 0; ry < n; ry++) {
            for (i64 rx = ry; rx < n; rx++) {
                if (ss[ay + ry][ax + rx] != ss[ay + rx][ax + ry]) err++;
            }
        }
        if (!err) ans += min(ay, ax) + 1;
    }

    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
