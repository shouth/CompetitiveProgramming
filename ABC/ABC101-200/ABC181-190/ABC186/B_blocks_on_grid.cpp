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
    i64 H, W;
    cin >> H >> W;

    i64 amin = INF;
    i64 ans = 0;
    for (i64 i = 0; i < H * W; i++) {
        i64 A;
        cin >> A;
        if (amin > A) {
            ans += (amin - A) * i;
            amin = A;
        } else {
            ans += A - amin;
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