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
    i64 T;
    cin >> T;

    for (i64 _ = 0; _ < T; _++) {
        i64 N, M;
        cin >> N >> M;

        i64 ans = -INF;
        i64 B = 0, C = 0;
        for (i64 i = 0; i < N; i++) {
            i64 x, y;
            cin >> x >> y;

            i64 Bl = B + x, Br = B + x * y;
            if (Bl >= 0 && Br < 0) {
                i64 n = min(y, B / abs(x));
                ans = max(ans, C + (Bl + B + x * n) * n / 2);
            }
            B = Br;
            ans = max(ans, C + Bl);
            C += (Bl + Br) * y / 2;
            ans = max(ans, C);
        }
        cout << max(ans, C) << "\n";
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
