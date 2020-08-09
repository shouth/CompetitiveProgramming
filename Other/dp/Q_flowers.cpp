#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

template<typename T, typename Op>
struct segment_tree {
    size_t offset;
    vector<T> v;

    const T unit_;
    const Op op_;

    segment_tree(size_t size, const T &unit = T(), const Op &op = Op()): unit_(unit), op_(op) {
        offset = 1;
        while (offset < size) offset <<= 1;
        v.assign(offset << 1, unit);
        offset--;
    }

    void update(size_t i, const T &x) {
        i += offset;
        v[i] = x;
        while (i >>= 1) {
            v[i] = op_(v[i << 1 | 0], v[i << 1 | 1]);
        }
    }

    T query(size_t l, size_t r) {
        T lv = unit_, rv = unit_;
        for (l += offset, r += offset; l < r; l >>= 1, r >>= 1) {
            if (l & 1) lv = op_(lv, v[l++]);
            if (r & 1) rv = op_(v[--r], rv);
        }
        return op_(lv, rv);
    }
};

void solve() {
    i64 n;
    cin >> n;
    vector<i64> h(n);
    for (auto& e : h) cin >> e;
    vector<i64> a(n);
    for (auto& e : a) cin >> e;

    auto maximum = [](i64 x, i64 y) { return max(x, y); };
    segment_tree<i64, decltype(maximum)> dp(n, 0, maximum);
    for (i64 i = 0; i < n; i++) {
        dp.update(h[i], dp.query(1, h[i]) + a[i]);
    }
    cout << dp.query(1, n + 1) << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
