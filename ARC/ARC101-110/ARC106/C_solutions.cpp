#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 N, M;
    cin >> N >> M;
    if (M < 0 || M == N || (N >= 2 && M == N - 1)) {
        cout << -1 << "\n";
        return;
    }

    if (M == 0) {
        i64 l = 1, r = 2;
        for (i64 i = 0; i < N; i++) {
            cout << l << " " << r << "\n";
            l += 2, r += 2;
        }
        return;
    }

    i64 l = 1, r = 2;
    for (i64 i = 0; i < N - M - 2; i++) {
        cout << l << " " << r << "\n";
        l += 2, r += 2;
    }

    cout << l << " " << l + (i64) 1e7 << "\n";
    l += 2, r += 2;
    for (i64 i = 0; i < M + 1; i++) {
        cout << l << " " << r << "\n";
        l += 2, r += 2;
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
