#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 N;
    cin >> N;

    vector<p64> ps(N);
    for (auto& [ x, y ] : ps) cin >> x >> y;

    for (i64 i = 0; i < N; i++) {
        for (i64 j = i + 1; j < N; j++) {
            for (i64 k = j + 1; k < N; k++) {
                auto& [ xi, yi ] = ps[i];
                auto& [ xj, yj ] = ps[j];
                auto& [ xk, yk ] = ps[k];

                i64 dx1 = xj - xi, dy1 = yj - yi;
                i64 dx2 = xk - xj, dy2 = yk - yj;

                if (dx1 * dy2 == dx2 * dy1) {
                    cout << "Yes" << endl;
                    return;
                }
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