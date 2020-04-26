#include<bits/stdc++.h>
using namespace std;

using i64 = int_fast64_t;
using f64 = double;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 n;
    cin >> n;
    
    i64 ans = 0;
    i64 l = 0, r = 0, lr = 0;
    for (i64 i = 0; i < n; i++) {
        string s;
        cin >> s;

        if (s.front() == 'B' && s.back() == 'A') lr++;
        else if (s.front() == 'B') l++;
        else if (s.back() == 'A') r++;

        for (i64 j = 0; j + 1 < (i64) s.size(); j++) {
            if (s[j] == 'A' && s[j + 1] == 'B') ans++;
        }
    }

    if (lr > 0) {
        ans += lr - 1;
        if (l > 0) ans++, l--;
        if (r > 0) ans++, r--;
    }
    ans += min(l, r);
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
