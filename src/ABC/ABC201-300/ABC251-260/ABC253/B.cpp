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
    i64 H, W;
    cin >> H >> W;
    i64 sx, sy, gx, gy;
    i64 cnt = 0;
    for (i64 i = 0; i < H; ++i) {
        for (i64 j = 0; j < W; ++j) {
            char s;
            cin >> s;
            if (s == 'o') {
                if (cnt == 0) {
                    sx = i, sy = j;
                } else {
                    gx = i, gy = j;
                }
                ++cnt;
            }
        }
    }
    cout << abs(sx - gx) + abs(sy - gy) << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
