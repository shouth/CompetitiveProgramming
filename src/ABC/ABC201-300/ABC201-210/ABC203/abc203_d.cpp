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
    i64 N, K;
    cin >> N >> K;

    auto A = vector(N, vector<i64>(N));
    for (auto &v : A) {
        for (auto &e : v) {
            cin >> e;
        }
    }

    i64 l = -1, r = 1e9;
    auto gt = vector(N + 1, vector<i64>(N + 1));
    while (abs(r - l) > 1) {
        i64 m = (r - l) / 2 + l;

        for (i64 i = 0; i < N; ++i) {
            for (i64 j = 0; j < N; ++j) {
                gt[i + 1][j + 1] = A[i][j] > m;
            }
        }
        for (i64 i = 0; i <= N; ++i) {
            for (i64 j = 0; j < N; ++j) {
                gt[i][j + 1] += gt[i][j];
            }
        }
        for (i64 i = 0; i < N; ++i) {
            for (i64 j = 0; j <= N; ++j) {
                gt[i + 1][j] += gt[i][j];
            }
        }

        bool flag = false;
        for (i64 i = 0; i + K <= N; ++i) {
            for (i64 j = 0; j + K <= N; ++j) {
                flag |= gt[i + K][j + K] - gt[i + K][j] - gt[i][j + K] + gt[i][j] < K * K / 2 + 1;
            }
        }
        (flag ? r : l) = m;
    }
    cout << r << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
