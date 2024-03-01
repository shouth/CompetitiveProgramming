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

void solve() {
    i64 N, Q;
    cin >> N >> Q;
    auto AX = vector<p64>();
    AX.reserve(N + Q);
    i64 sum = 0;
    for (i64 i = 0; i < N; i++) {
        i64 A;
        cin >> A;
        AX.emplace_back(A, -1);
        sum += A;
    }
    for (i64 i = 0; i < Q; i++) {
        i64 X;
        cin >> X;
        AX.emplace_back(X, i);
    }
    sort(all(AX));

    auto ans = vector<i64>(Q);
    i64 u = 0, pax = 0;
    for (auto [ ax, i ] : AX) {
        pax = ax - pax;
        sum += u * pax - (N - u) * pax;
        if (i < 0) {
            u++;
        } else {
            ans[i] = sum;
        }
        pax = ax;
    }

    for (auto e : ans) {
        cout << e << "\n";
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
