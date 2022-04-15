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

i64 maxop(i64 a, i64 b) { return max(a, b); }
i64 maxe() { return 0; }

i64 minop(i64 a, i64 b) { return min(a, b); }
i64 mine() { return INF; }

void solve() {
    i64 N, X, Y;
    cin >> N >> X >> Y;
    auto A = vector<i64>(N);
    for (auto &a : A) cin >> a;

    auto maxt = segtree<i64, maxop, maxe>(A);
    auto mint = segtree<i64, minop, mine>(A);

    i64 ans = 0;
    for (i64 l = 0; l < N; l++) {
        int maxlower = maxt.max_right((int) l, [&](i64 n) { return n < X; });
        int maxupper = maxt.max_right((int) l, [&](i64 n) { return n <= X; });
        int minlower = mint.max_right((int) l, [&](i64 n) { return n > Y; });
        int minupper = mint.max_right((int) l, [&](i64 n) { return n >= Y; });
        ans += max(0, min(maxupper, minupper) - max(maxlower, minlower));
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
