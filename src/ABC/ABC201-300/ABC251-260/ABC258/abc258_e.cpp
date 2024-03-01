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
    i64 N, Q, X;
    cin >> N >> Q >> X;
    auto W = vector<i64>(N + 1);
    for (i64 i = 1; i <= N; ++i) cin >> W[i];
    inclusive_scan(W.begin(), W.end(), W.begin());

    auto table = vector(40, vector<i64>(N));
    auto count = vector<i64>(N);
    for (i64 i = 0; i < N; ++i) {
        i64 l = i, r = 1e9 + 10;
        while (abs(r - l) > 1) {
            i64 m = (r - l) / 2 + l;
            i64 v = (m / N) * W.back() + W[m % N] - (i / N) * W.back() - W[i % N];
            (v < X ? l : r) = m;
        }

        table[0][i] = r % N;
        count[i] = r - i;
    }
    for (i64 i = 1; i < 40; ++i) {
        for (i64 j = 0; j < N; ++j) {
            table[i][j] = table[i - 1][table[i - 1][j]];
        }
    }

    for (i64 _ = 0; _ < Q; _++) {
        i64 K;
        cin >> K, --K;
        i64 pos = 0;
        for (i64 i = 0; K > 0; ++i, K >>= 1) {
            if (K & 1) {
                pos = table[i][pos];
            }
        }
        cout << count[pos] << "\n";
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
