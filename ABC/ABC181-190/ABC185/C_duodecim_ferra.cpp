#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

template<typename T>
T c(i64 n, i64 k) {
    if (k < 0 || n < k) return 0;
    if (n - k < k) k = n - k;
    T res = 1;
    for (i64 i = 1; i <= k; i++) res = res * (n - i + 1) / i;
    return res;
}

void solve() {
    i64 L;
    cin >> L;
    cout << c<i64>(L - 1, 11) << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}