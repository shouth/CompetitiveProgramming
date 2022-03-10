#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 N;
    cin >> N;

    i64 ans = 0;
    for (i64 i = 1; i <= N; i++) {
        bool flag = true;
        for (i64 j = i; j > 0; j /= 10) {
            if (j % 10 == 7) flag = false;
        }
        for (i64 j = i; j > 0; j /= 8) {
            if (j % 8 == 7) flag = false;
        }
        if (flag) ans++;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}