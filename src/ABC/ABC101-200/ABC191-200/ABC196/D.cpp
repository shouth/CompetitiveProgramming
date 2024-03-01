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

using namespace std;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define yes(x) ((x) ? "yes" : "no")
#define Yes(x) ((x) ? "Yes" : "No")

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

i64 H, W, A, B;

i64 dfs(i64 depth, i64 room, i64 a, i64 b) {
    if (depth == H * W) return 1;
    if (a < 0 || b < 0) return 0;
    if (room & 1 << depth) return dfs(depth + 1, room, a, b);

    room |= 1ll << depth;
    i64 ret = dfs(depth + 1, room, a, b - 1);
    if (depth % W < W - 1 && ~room & 1 << (depth + 1)) ret += dfs(depth + 1, room | (1ll << (depth + 1)), a - 1, b);
    if (depth / W < H - 1) ret += dfs(depth + 1, room | (1ll << (depth + W)), a - 1, b);
    return ret;
}

void solve() {
    cin >> H >> W >> A >> B;
    cout << dfs(0, 0, A, B) << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
