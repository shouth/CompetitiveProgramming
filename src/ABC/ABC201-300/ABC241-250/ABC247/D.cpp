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
using m64 = modint1000000007;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 Q;
    cin >> Q;

    auto q = deque<p64>();
    for (i64 _ = 0; _ < Q; _++) {
        i64 n;
        cin >> n;

        if (n == 1) {
            i64 x, c;
            cin >> x >> c;

            q.emplace_back(x, c);
        } else {
            i64 c;
            cin >> c;

            i64 ans = 0;
            while (!q.empty()) {
                auto &[ xx, cc ] = q[0];

                if (cc <= c) {
                    ans += cc * xx;
                    c -= cc;
                    q.pop_front();
                } else {
                    ans += c * xx;
                    cc -= c;
                    break;
                }
            }
            cout << ans << endl;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
