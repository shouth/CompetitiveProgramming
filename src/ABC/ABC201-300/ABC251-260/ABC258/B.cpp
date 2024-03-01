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
    auto A = vector<string>(N);
    for (auto &e : A) cin >> e;

    i64 ans = 0;
    for (i64 i = 0; i < N; ++i) {
        for (i64 j = 0; j < N; ++j) {
            auto dxy = vector<i64> { 0, 1, 1, -1, 0, -1, -1, 1, 0 };
            for (i64 dir = 0; dir < 8; ++dir) {
                i64 cand = 0;
                for (i64 k = 0; k < N; ++k) {
                    i64 ni = (i + k * dxy[dir] + N) % N;
                    i64 nj = (j + k * dxy[dir + 1] + N) % N;
                    cand = cand * 10 + A[ni][nj] - '0';
                }
                ans = max(ans, cand);
            }
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
