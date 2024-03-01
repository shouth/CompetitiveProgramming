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

struct MoOp {
    using Range = std::vector<i64>;

    vector<i64> cnts;
    i64 cnt = 0;

    MoOp(i64 size, const Range &range): cnts(size) { }

    void add_left(const Range &range, i64 i) { cnt += cnts[range[i]]++ & 1; }
    void add_right(const Range &range, i64 i) { add_left(range, i); }

    void erase_left(const Range &range, i64 i) { cnt -= --cnts[range[i]] & 1; }
    void erase_right(const Range &range, i64 i) { erase_left(range, i); }

    i64 save() { return cnt; }
};

template<class Op>
auto mo(i64 size, const typename Op::Range &range, const vector<p64> &queries) {
    i64 q = (i64) queries.size();
    i64 bs = size / min<i64>(size, sqrt(q));
    auto ord = vector<i64>(q);
    iota(begin(ord), end(ord), 0);
    sort(begin(ord), end(ord), [&](i64 a, i64 b) {
        auto [ al, ar ] = queries[a];
        auto [ bl, br ] = queries[b];
        i64 ablock = al / bs, bblock = bl / bs;
        return ablock != bblock ? ablock < bblock : (ablock & 1) ? ar > br : ar < br;
    });

    i64 l = 0, r = 0;
    auto self = Op(size, range);
    auto result = vector<decltype(self.save())>(queries.size());
    for (auto idx : ord) {
        auto [ li, ri ] = queries[idx];
        while (l > li) self.add_left(range, --l);
        while (r < ri) self.add_right(range, r++);
        while (l < li) self.erase_left(range, l++);
        while (r > ri) self.erase_right(range, --r);
        result[idx] = self.save();
    }
    return result;
}

void solve() {
    i64 N;
    cin >> N;
    auto A = vector<i64>(N);
    for (auto &e : A) cin >> e, e--;

    i64 Q;
    cin >> Q;
    auto queries = vector<p64>(Q);
    for (auto &[ l, r ] : queries) cin >> l >> r, l--;

    for (auto &e : mo<MoOp>(N, A, queries)) {
        cout << e << "\n";
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
