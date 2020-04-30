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

    i64 ans = 0;
    i64 i = n - 1;
    while (i > 2) {
        if (s[i] != s[i - 1]) ans += 1, i -= 1;
        else ans += 2, i -= 3;
    }

    switch (i) {
    case 0:
        ans += 1;
        break;
    case 1:
        ans += s[0] != s[1] ? 2 : 1;
        break;
    case 2:
        ans += s[0] != s[1] && s[1] != s[2] ? 3 : 2;
        break;
    }

    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
