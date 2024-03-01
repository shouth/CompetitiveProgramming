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
#include <variant>
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
    i64 N, M, Q;
    cin >> N >> M >> Q;

    struct op1 { i64 l, r, x; };
    struct op2 { i64 i, x; };
    struct op3 { i64 n, i, j; };

    using op = variant<op1, op2, op3>;

    auto ops = vector<op>();
    i64 cnt = 0;
    for (i64 _ = 0; _ < Q; ++_) {
        i64 q;
        cin >> q;

        switch (q) {
            case 1: {
                i64 l, r, x;
                cin >> l >> r >> x, --l;
                ops.push_back(op1 { l, r, x });
                break;
            }
            case 2: {
                i64 i, x;
                cin >> i >> x, --i;
                ops.push_back(op2 { i, x });
                break;
            }
            case 3: {
                i64 i, j;
                cin >> i >> j, --i;
                ops.push_back(op3 { cnt, i, j });
                ++cnt;
                break;
            }
        }
    }

    struct pending_op { i64 n, j, x; };

    auto sum = fenwick_tree<i64>(M + 1);
    auto pending = vector(N, vector<pending_op>());
    auto ans = vector<i64>(cnt);
    reverse(all(ops));
    for (auto op : ops) {
        switch (op.index()) {
            case 0: {
                auto [ l, r, x ] = std::get<0>(op);
                sum.add(l, x);
                sum.add(r, -x);
                break;
            }
            case 1: {
                auto [ i, x ] = std::get<1>(op);
                for (auto [ n, j, y ] : pending[i]) {
                    ans[n] = x + sum.sum(0, j) - y;
                }
                pending[i].clear();
                break;
            }
            case 2: {
                auto [ n, i, j ] = std::get<2>(op);
                pending[i].push_back({ n, j, sum.sum(0, j) });
                break;
            }
        }
    }
    for (const auto &v : pending) {
        for (auto [ n, j, y ] : v) {
            ans[n] = sum.sum(0, j) - y;
        }
    }

    for (auto e : ans) {
        cout << e << "\n";
    }
    cout << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
