#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    string s;
    cin >> s;

    i64 ans = INF;
    for (char c = 'a'; c <= 'z'; c++) {
        string a = s;
        i64 can = 0;
        for (i64 i = s.size(); i > 0; i--) {
            if (all_of(begin(a), begin(a) + i, [&](char d) { return d == c; })) break;
            for (i64 j = 0; j + 1 < i; j++) {
                if (a[j] != c && a[j + 1] != c) continue;
                a[j] = c;
            }
            can++;
        }
        ans = min(ans, can);
    }

    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
