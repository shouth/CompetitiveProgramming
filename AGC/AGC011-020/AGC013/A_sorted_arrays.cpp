#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 n;
    cin >> n;
    vector<i64> a(n);
    for (auto& e : a) cin >> e;

    i64 ans = 0;
    for (i64 i = 0; i < n; i++) {
        while (i + 1 < n && a[i] == a[i + 1]) i++;

        if (i + 1 < n && a[i] < a[i + 1]) {
            while (i + 1 < n && a[i] <= a[i + 1]) i++;
        } else if (i + 1 < n && a[i] > a[i + 1]) {
            while (i + 1 < n && a[i] >= a[i + 1]) i++;
        }

        ans++;
    }

    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
