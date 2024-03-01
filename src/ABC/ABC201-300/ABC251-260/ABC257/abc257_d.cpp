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
    i64 N;
    cin >> N;

    auto catapalts = vector<tuple<i64, i64, i64>>(N);
    for (auto &[ x, y, P ] : catapalts) cin >> x >> y >> P;

    auto S = vector(N, vector(N, i64(0)));
    for (i64 a = 0; a < N; a++) {
        for (i64 b = 0; b < N; b++) {
            auto [ ax, ay, aP ] = catapalts[a];
            auto [ bx, by, bP ] = catapalts[b];
            i64 dist = abs(ax - bx) + abs(ay - by);
            S[a][b] = (dist + aP - 1) / aP;
        }
    }

    for (i64 k = 0; k < N; k++) {
        for (i64 i = 0; i < N; i++) {
            for (i64 j = 0; j < N; j++) {
                S[i][j] = min(S[i][j], max(S[i][k], S[k][j]));
            }
        }
    }

    i64 ans = INF;
    for (auto &e : S) {
        ans = min(ans, *max_element(all(e)));
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
