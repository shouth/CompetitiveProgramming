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
using m64 = modint998244353;

constexpr i64 INF = std::numeric_limits<i64>::max() / 2;

void solve() {
    i64 N, Q;
    cin >> N >> Q;
    auto A = fenwick_tree<m64>(N);
    auto iA = fenwick_tree<m64>(N);
    auto iiA = fenwick_tree<m64>(N);
    for (i64 i = 1; i <= N; ++i) {
        i64 Ai;
        cin >> Ai;
        A.add(i - 1, m64(Ai));
        iA.add(i - 1, m64(Ai) * i);
        iiA.add(i - 1, m64(Ai) * i * i);
    }

    for (i64 _ = 0; _ < Q; ++_) {
        i64 q;
        cin >> q;

        switch (q) {
            case 1: {
                i64 x, v;
                cin >> x >> v;
                A.add(x - 1, -A.sum(x - 1, x) + m64(v));
                iA.add(x - 1, -iA.sum(x - 1, x) + m64(v) * x);
                iiA.add(x - 1, -iiA.sum(x - 1, x) + m64(v) * x * x);
                break;
            }
            case 2: {
                i64 x;
                cin >> x;
                m64 ans = 0;
                ans += iiA.sum(0, x) / 2;
                ans -= iA.sum(0, x) * ((x + 1) + (x + 2)) / 2;
                ans += A.sum(0, x) * (x + 1) * (x + 2) / 2;
                cout << ans.val() << endl;
                break;
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
