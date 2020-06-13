#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 n, q;
    cin >> n >> q;

    vector<i64> top(n), parent(n, -1);
    iota(all(top), 0);

    for (i64 i = 0; i < q; i++) {
        i64 f, t, x;
        cin >> f >> t >> x, f--, t--, x--;
        i64 tmp = top[f];
        top[f] = parent[x];
        parent[x] = top[t];
        top[t] = tmp;
    }

    vector<i64> ans(n);
    for (i64 i = 0; i < n; i++) {
        for (i64 c = top[i]; c != -1; c = parent[c]) {
            ans[c] = i + 1;
        }
    }
    for (auto& e : ans) cout << e << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
