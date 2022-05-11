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

template<typename F, typename G, typename H, typename T, typename S>
struct lazy_segment_tree {
    size_t offset, height;
    vector<T> data, lazy;

    const F f_;
    const G g_;
    const H h_;
    const T unit_;
    const S lazy_unit_;

    lazy_segment_tree(
        size_t size,
        const F f, const G g, const H h,
        const T unit, const S lazy_unit):
        f_(f), g_(g), h_(h), unit_(unit), lazy_unit_(lazy_unit) {
        offset = 1, height = 0;
        while (offset < size) offset <<= 1, height++;
        data.assign(offset << 1, unit);
        lazy.assign(offset << 1, lazy_unit);
        offset--;
    }

    inline void propagate(size_t i) {
        if (lazy[i] == lazy_unit_) return;
        lazy[i << 1 | 0] = h_(lazy[i << 1 | 0], lazy[i]);
        lazy[i << 1 | 1] = h_(lazy[i << 1 | 1], lazy[i]);
        data[i] = reflect(i);
        lazy[i] = lazy_unit_;
    }

    inline void thrust(size_t i) {
        for (size_t j = height; j > 0; j--) propagate(i >> j);
    }

    inline T reflect(size_t i) {
        return lazy[i] == lazy_unit_ ? data[i] : g_(data[i], lazy[i]);
    }

    void update(size_t l, size_t r, const T x) {
        thrust(l += offset);
        thrust(r += offset - 1);
        for (size_t li = l, ri = r + 1; li < ri; li >>= 1, ri >>= 1) {
            if (li & 1) lazy[li] = h_(lazy[li], x), li++;
            if (ri & 1) ri--, lazy[ri] = h_(lazy[ri], x);
        }
        while (l >>= 1) data[l] = f_(reflect(l << 1 | 0), reflect(l << 1 | 1));
        while (r >>= 1) data[r] = f_(reflect(r << 1 | 0), reflect(r << 1 | 1));
    }

    T query(size_t l, size_t r) {
        thrust(l += offset);
        thrust(r += offset - 1);
        T lv = unit_, rv = unit_;
        for (size_t li = l, ri = r + 1; li < ri; li >>= 1, ri >>= 1) {
            if (li & 1) lv = f_(lv, reflect(li)), li++;
            if (ri & 1) ri--, rv = f_(reflect(ri), rv);
        }
        return f_(lv, rv);
    }
};

void solve() {
    i64 N, Q;
    cin >> N >> Q;

    auto f = [](i64 a, i64 b) { return min(a, b); };
    lazy_segment_tree row(N, f, f, f, N, N), col(N, f, f, f, N, N);
    i64 ans = (N - 2) * (N - 2);
    for (i64 i = 0; i < Q; i++) {
        i64 t, x;
        cin >> t >> x;

        if (t == 1) {
            i64 s = col.query(x, x + 1);
            ans -= s - 2;
            row.update(2, s, x);
        } else {
            i64 s = row.query(x, x + 1);
            ans -= s - 2;
            col.update(2, s, x);
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
