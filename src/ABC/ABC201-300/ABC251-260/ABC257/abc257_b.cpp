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
    i64 N, K, Q;
    cin >> N >> K >> Q;
    auto A = vector<i64>(K);
    for (auto &e : A) cin >> e;

    for (i64 _ = 0; _ < Q; _++) {
        i64 L;
        cin >> L, L--;
        if (A[L] == N) continue;
        if (L + 1 < K && A[L] + 1 == A[L + 1]) continue;
        A[L]++;
    }
    for (i64 i = 0; i < K; i++) {
        cout << (i ? " " : "") << A[i];
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
