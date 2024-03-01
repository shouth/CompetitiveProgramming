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

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 H, W, N, M;
    cin >> H >> W >> N >> M;

    auto bulbs = vector(N, p64());
    for (auto& [ A, B ] : bulbs) cin >> A >> B, A--, B--;

    auto blocks = vector(M, p64());
    for (auto& [ C, D ] : blocks) cin >> C >> D, C--, D--;

    auto lights = vector(H, vector(W, bitset<2>()));
    for (auto& [ C, D ] : blocks) lights[C][D] = 0b11;

    for (auto& [ A, B ] : bulbs) {
        if (!lights[A][B][0]) {
            lights[A][B][0] = 1;
            for (i64 y = A + 1; y < H; y++) {
                if (lights[y][B][0]) break;
                lights[y][B][0] = 1;
            }
            for (i64 y = A - 1; y >= 0; y--) {
                if (lights[y][B][0]) break;
                lights[y][B][0] = 1;
            }
        }
        if (!lights[A][B][1]) {
            lights[A][B][1] = 1;
            for (i64 x = B + 1; x < W; x++) {
                if (lights[A][x][1]) break;
                lights[A][x][1] = 1;
            }
            for (i64 x = B - 1; x >= 0; x--) {
                if (lights[A][x][1]) break;
                lights[A][x][1] = 1;
            }
        }
    }

    i64 cnt = 0;
    for (auto& es : lights) {
        for (auto& e : es) {
            if (e.any()) cnt++;
        }
    }
    cout << cnt - M << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
