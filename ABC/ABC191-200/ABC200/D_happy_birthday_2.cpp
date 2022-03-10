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
    auto A = vector<i64>(N);
    for (auto &e : A) cin >> e;

    auto rem = vector<i64>(200);
    i64 n = min(N, 8l);
    for (i64 x = 0; x < 1 << n; x++) {
        i64 s = 0;
        for (i64 i = 0; i < n; i++) {
            s += A[i] * ((x >> i) & 1);
        }
        s %= 200;
        if (i64 y = rem[s]) {
            cout << "Yes" << endl;
            auto f = [&](i64 a) {
                cout << __builtin_popcountll(a);
                for(i64 i = 0; i < n; i++) {
                    if ((a >> i) & 1) cout << " " << i + 1;
                }
                cout << endl;
            };
            f(x), f(y);
            return;
        }
        rem[s] = x;
    }
    cout << "No" << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
