#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

template<typename T>
T c(i64 n, i64 k) {
    if (k < 0 || n < k) return 0;
    if (n - k < k) k = n - k;
    T res = 1;
    for (i64 i = 1; i <= k; i++) res = res * (n - i + 1) / i;
    return res;
}

void solve() {
    i64 n, p;
    cin >> n >> p;
    i64 odd = 0, even = 0;
    for (i64 i = 0; i < n; i++) {
        i64 a;
        cin >> a;
        (a % 2 ? odd : even)++;
    }

    i64 ans0 = 1l << even;
    i64 ans1 = 0;
    for (i64 i = p; i <= odd; i += 2) ans1 += c<i64>(odd, i);
    cout << ans0 * ans1 << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
