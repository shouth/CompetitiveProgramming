#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 n, k;
    cin >> n >> k;
    vector<i64> a(n);
    for (auto& e : a) cin >> e;

    for (i64 i = k; i < n; i++) {
        cout << (a[i - k] < a[i] ? "Yes" : "No") << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
