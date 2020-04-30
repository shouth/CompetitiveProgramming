#include<bits/stdc++.h>
using namespace std;

using i64 = int_fast64_t;
using f64 = double;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 n, p;
    cin >> n >> p;
    map<i64, i64> factor;
    for (i64 i = 2; i * i <= p; i++) {
        while (p % i == 0) {
            factor[i]++;
            p /= i;
        }
    }
    if (p != 1) factor[p]++;

    i64 ans = 1;
    for (auto& e : factor) ans *= (i64) pow(e.first, e.second / n);
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
