#include<bits/stdc++.h>
using namespace std;

using i64 = int_fast64_t;
using f64 = double;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    string s;
    cin >> s;
    i64 n = s.size();

    map<i64, i64> cnt;
    cnt[0] = 1;
    i64 d = 1, x = 0;
    for (i64 i = n - 1; i >= 0; i--) {
        x = (x + (s[i] - '0') * d) % 2019;
        cnt[x]++;
        d = d * 10 % 2019;
    }

    i64 ans = 0;
    for (auto& e : cnt) ans += e.second * (e.second - 1) / 2;
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
