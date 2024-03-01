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

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

template<typename T>
struct binary_indexed_tree {
    vector<T> t_;
    i64 n_;

    binary_indexed_tree(size_t n): t_(n + 1), n_(n + 1) {}

    void add(i64 i, T x) {
        for (; i <= n_; i += i & -i) t_[i] += x;
    }

    T sum(i64 i) {
        T res = 0;
        for (; i > 0; i -= i & -i) res += t_[i];
        return res;
    }
};

struct query { i64 idx, l, r; };

void solve() {
    i64 n, q;
    cin >> n >> q;
    vector<i64> c(n);
    for (auto& e : c) cin >> e;
    vector<query> qs(q);
    for (i64 i = 0; i < q; i++) {
        auto& [ idx, l, r ] = qs[i];
        idx = i;
        cin >> l >> r;
    }
    sort(all(qs), [](const query &x, const query &y) { return x.r < y.r; });

    vector<i64> right(n), ans(q);
    binary_indexed_tree<i64> cnt(n);
    i64 i = 0;
    for (auto& [ idx, l, r ] : qs) {
        for (; i < r; i++) {
            if (right[c[i]]) cnt.add(right[c[i]], -1);
            right[c[i]] = i + 1;
            cnt.add(right[c[i]], 1);
        }
        ans[idx] = cnt.sum(r) - cnt.sum(l - 1);
    }
    for (auto& e : ans) cout << e << "\n";
    cout << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
