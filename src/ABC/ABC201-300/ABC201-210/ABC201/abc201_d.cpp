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

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 H, W;
    cin >> H >> W;
    auto A = vector<string>(H);
    for (auto &e : A) cin >> e;

    auto dp = vector(H, vector(W, i64()));
    auto score = [&](i64 h, i64 w) { return A[h][w] == '+' ? 1 : -1; };
    for (i64 h = H - 1; h >= 0; h--) {
        for (i64 w = W - 1; w >= 0; w--) {
            if (h == H - 1 && w == W - 1) continue;
            if ((h + w) % 2) {
                dp[h][w] = INF;
                if (h < H - 1) dp[h][w] = min(dp[h][w], dp[h + 1][w] - score(h + 1, w));
                if (w < W - 1) dp[h][w] = min(dp[h][w], dp[h][w + 1] - score(h, w + 1));
            } else {
                dp[h][w] = -INF;
                if (h < H - 1) dp[h][w] = max(dp[h][w], dp[h + 1][w] + score(h + 1, w));
                if (w < W - 1) dp[h][w] = max(dp[h][w], dp[h][w + 1] + score(h, w + 1));
            }
        }
    }
    if (dp[0][0] > 0) {
        cout << "Takahashi" << endl;
    } else if (dp[0][0] < 0) {
        cout << "Aoki" << endl;
    } else {
        cout << "Draw" << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
