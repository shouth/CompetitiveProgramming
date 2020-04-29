#include<bits/stdc++.h>
using namespace std;

using i64 = int_fast64_t;
using f64 = double;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    string s;
    cin >> s;
    i64 n = s.size() + 1;

    vector<i64> ans(n);
    for (i64 i = 0; i + 1 < n; i++) {
        if (s[i] == '<') ans[i + 1] = ans[i] + 1;
    }
    for (i64 i = n - 2; i >= 0; i--) {
        if (s[i] == '>') ans[i] = max(ans[i], ans[i + 1] + 1);
    }

    cout << accumulate(begin(ans), end(ans), 0l) << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
