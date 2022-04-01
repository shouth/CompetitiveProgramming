#include<bits/stdc++.h>
#include<atcoder/all>

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define yes(x) ((x) ? "yes" : "no")
#define Yes(x) ((x) ? "Yes" : "No")

using namespace std;
using namespace atcoder;

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;
using m64 = modint1000000007;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 N;
    cin >> N;

    auto xs = vector<i64>(2 * N + 2);
    while (1) {
        for (i64 i = 1; i <= 2 * N + 1; i++) {
            if (not xs[i]) {
                cout << i << endl;
                xs[i] = 1;
                break;
            }
        }
        i64 y;
        cin >> y;
        if (y == 0) {
            break;
        }
        xs[y] = 1;
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
