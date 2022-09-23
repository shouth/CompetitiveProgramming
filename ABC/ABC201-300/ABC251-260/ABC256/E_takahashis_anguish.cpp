#pragma clang diagnostic ignored "-Wunused-variable"
#pragma clang diagnostic ignored "-Wunused-const-variable"

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

constexpr i64 INF = std::numeric_limits<i64>::max() / 2;

void solve() {
    i64 N;
    cin >> N;
    auto X = vector<i64>(N);
    for (auto &e : X) cin >> e, --e;
    auto C = vector<i64>(N);
    for (auto &e : C) cin >> e;

    i64 ans = 0;
    auto visited = vector<i64>(N, -1);
    for (i64 i = 0; i < N; ++i) {
        if (visited[i] != -1) {
            continue;
        }

        i64 p = i;
        for (; visited[p] == -1; p = X[p]) {
            visited[p] = i;
        }

        if (visited[p] != i) {
            continue;
        }

        i64 m = C[p];
        for (i64 q = X[p]; q != p; q = X[q]) {
            m = min(m, C[q]);
        }
        ans += m;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
