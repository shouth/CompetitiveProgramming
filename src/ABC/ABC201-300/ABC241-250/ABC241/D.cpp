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
    i64 Q;
    cin >> Q;

    auto A = multiset<i64>();
    for (i64 _ = 0; _ < Q; _++) {
        i64 t;
        cin >> t;

        if (t == 1) {
            i64 x;
            cin >> x;
            A.emplace(x);
        } else {
            i64 x, k;
            cin >> x >> k;

            if (t == 2) {
                auto itr = A.upper_bound(x);
                while (itr != A.begin() && k > 0) itr--, k--;
                cout << (k != 0 ? -1 : *itr) << "\n";
            } else {
                auto itr = A.lower_bound(x);
                k--;
                while (itr != A.end() && k > 0) itr++, k--;
                cout << (k != 0 || itr == A.end() ? -1 : *itr) << "\n";
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
