#include <utility>
#include <bitset>
#include <tuple>
#include <string>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <complex>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <atcoder/all>

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

i64 e() { return 0; }

void solve() {
    i64 N, Q;
    cin >> N >> Q;
    auto A = vector<i64>(N);
    for (auto &e : A) cin >> e;
    auto B = vector<i64>(N);
    for (auto &e : B) cin >> e;

    auto C = vector<i64>(N);
    adjacent_difference(all(A), begin(C));
    auto D = vector<i64>(N);
    adjacent_difference(all(B), begin(D));

    auto Cseg = segtree<i64, gcd, e>(C);
    auto Dseg = segtree<i64, gcd, e>(D);

    for (i64 _ = 0; _ < Q; _++) {
        i64 h1, h2, w1, w2;
        cin >> h1 >> h2 >> w1 >> w2;
        i64 ans = A[h1 - 1] + B[w1 - 1];
        ans = gcd(ans, Cseg.prod(h1, h2));
        ans = gcd(ans, Dseg.prod(w1, w2));
        cout << ans << "\n";
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
