#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 n, m;
    cin >> n >> m;
    vector<i64> cnt(n);
    for (i64 i = 0; i < m; i++) {
        i64 a, b;
        cin >> a >> b, a--, b--;
        cnt[a]++, cnt[b]++;
    }

    i64 f = 0;
    for (auto& e : cnt) f += e % 2;
    cout << (f <= 1 ? "YES" : "NO") << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
