#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using f64 = double;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 n;
    cin >> n;
    string s;
    cin >> s;
    string a(begin(s), begin(s) + n), b(rbegin(s), rbegin(s) + n);

    map<pair<string, string>, i64> cnt;
    for (i64 i = 0; i < (1 << n); i++) {
        string ar, ab;
        for (i64 j = 0; j < n; j++) {
            ((i >> j) & 1 ? ar : ab).push_back(s[j]);
        }
        cnt[{ar, ab}]++;
    }

    i64 ans = 0;
    for (i64 i = 0; i <= n; i++) {
        vector<i64> sel(n);
        fill(begin(sel) + i, end(sel), 1);

        do {
            string br, bb;
            for (i64 j = 0; j < n; j++) {
                (sel[j] ? br : bb).push_back(b[j]);
            }
            ans += cnt[{br, bb}];
        } while (next_permutation(all(sel)));
    }

    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
