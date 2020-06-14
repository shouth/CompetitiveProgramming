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
    map<i64, i64> acnt;
    for (i64 i = 0; i < n; i++) {
        i64 a;
        cin >> a;
        acnt[a]++;
    }

    vector<i64> invalid(1e6 + 1);
    i64 ans = 0;
    for (auto& [ a, cnt ] : acnt) {
        if (invalid[a]) continue;
        if (cnt == 1) ans++;
        for (i64 i = 1; i * a <= (i64) 1e6; i++) invalid[i * a] = 1;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
