#include<bits/stdc++.h>
using namespace std;

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

void solve() {
    i64 n;
    cin >> n;
    vector<p64> rl(n);
    for (auto& e : rl) {
        i64 x, l;
        cin >> x >> l;
        e = { x + l, x - l };
    }

    sort(begin(rl), end(rl));

    i64 ans = 0;
    i64 cur = -INT64_MAX;
    for (auto& e : rl) {
        i64 r, l;
        tie(r, l) = e;
        if (cur <= l) {
            cur = r;
            ans++;
        }
    }

    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
