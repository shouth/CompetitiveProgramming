#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 a, b, c;
    cin >> a >> b >> c;
    i64 k;
    cin >> k;

    for (i64 i = 0; i <= k; i++) {
        for (i64 j = 0; i + j <= k; j++) {
            i64 na = a << i;
            i64 nb = b << j;
            i64 nc = c << (k - i - j);
            if (na < nb && nb < nc) {
                cout << "Yes" << endl;
                return;
            }
        }
    }

    cout << "No" << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
