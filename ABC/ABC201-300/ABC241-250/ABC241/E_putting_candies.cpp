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
    i64 N, K;
    cin >> N >> K;
    auto A = vector<i64>(N);
    for (auto &e : A) cin >> e;

    auto m = vector<i64>(N, -1);
    auto X = vector<i64>();
    X.emplace_back(0);
    for (i64 i = 0; m[X.back() % N] == -1; i++) {
        m[X.back() % N] = i;
        X.emplace_back(X.back() + A[X.back() % N]);
    }
    i64 s = m[X.back() % N];
    i64 ans = X[min(K, s)];
    K = max(K - s, i64(0));
    i64 l = X.size() - s - 1;
    ans += (X.back() - X[s]) * (K / l) + X[s + K % l] - X[s];
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
