#include<bits/stdc++.h>
using namespace std;

using i64 = int_fast64_t;
using f64 = double;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 n;
    cin >> n;
    map<i64, i64> mns, pls;
    for (i64 i = 0; i < n; i++) {
        i64 a;
        cin >> a;
        mns[i - a]++, pls[i + a]++;
    }

    i64 ans = 0;
    for (auto& e : mns) {
        i64 k, v;
        tie(k, v) = e;
        ans += v * pls[k];
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
