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

    vector<p64> AB(N);
    i64 x = 0;
    for (auto& [ A, B ] : AB) cin >> A >> B, x -= A;
    sort(all(AB), [](p64 &x, p64 &y) {
        return x.first * 2 + x.second > y.first * 2 + y.second;
    });

    i64 takahashi = 0;
    for (i64 i = 0; i < N; i++) {
        auto [ A, B ] = AB[i];
        x += 2 * A + B;
        if (x > 0) {
            cout << i + 1 << endl;
            return;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}