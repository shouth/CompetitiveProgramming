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
            if (l & 1) lv = op_(lv, v[l]), l++;
            if (r & 1) r--, rv = op_(v[r], rv);
        }
        return op_(lv, rv);
    }
};

void solve() {
    i64 N, K;
    cin >> N >> K;

    segment_tree dp(300'010, 0l, [](auto a, auto b) { return max(a, b); });
    for (i64 i = 0; i < N; i++) {
        i64 A;
        cin >> A, A++;
        i64 s = max(1l, A - K), e = min(300'001l, A + K);
        dp.update(A, dp.query(s, e + 1) + 1);
    }
    cout << dp.query(1, 300'002) << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
