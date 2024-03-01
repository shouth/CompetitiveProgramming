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

void solve() {
    i64 H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (auto& e : S) cin >> e;

    i64 ans = 0;
    vector<i64> d { 1, 0, 0, 1, 1 };
    for (i64 i = 0; i < H - 1; i++) {
        for (i64 j = 0; j < W - 1; j++) {
            i64 cnt = 0;
            for (i64 k = 0; k < 4; k++) {
                if (S[i + d[k]][j + d[k + 1]] == '#') cnt++;
            }
            if (cnt == 1 || cnt == 3) ans++;
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
