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
    i64 N, Q;
    cin >> N >> Q;

    auto balls = vector<i64>(N);
    auto indices = vector<i64>(N);
    iota(all(balls), 0);
    iota(all(indices), 0);
    for (i64 _ = 0; _ < Q; _++) {
        i64 x;
        cin >> x, x--;
        if (indices[x] + 1 < N) {
            i64 y = balls[indices[x] + 1];
            swap(balls[indices[x]], balls[indices[x] + 1]);
            swap(indices[x], indices[y]);
        } else {
            i64 y = balls[indices[x] - 1];
            swap(balls[indices[x]], balls[indices[x] - 1]);
            swap(indices[x], indices[y]);
        }
    }
    for (i64 i = 0; i < N; i++) {
        cout << (i ? " " : "") << balls[i] + 1;
    }
    cout << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
