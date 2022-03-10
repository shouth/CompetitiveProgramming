#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define yes(x) ((x) ? "yes" : "no")
#define Yes(x) ((x) ? "Yes" : "No")

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 N;
    cin >> N;

    i64 a0 = INF, a1 = INF, b0 = INF, b1 = INF;
    i64 a0i, b0i;

    auto update = [](i64 in, i64 ini, i64 &v0, i64 &v0i, i64 &v1) {
        if (in < v0) {
            v1 = v0;
            v0 = in, v0i = ini;
        } else if (in < v1) {
            v1 = in;
        }
    };

    for (i64 i = 0; i < N; i++) {
        i64 A, B;
        cin >> A >> B;
        update(A, i, a0, a0i, a1);
        update(B, i, b0, b0i, b1);
    }

    if (a0i != b0i) {
        cout << max(a0, b0) << endl;
    } else {
        cout << min({ a0 + b0, max(a0, b1), max(a1, b0) }) << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
