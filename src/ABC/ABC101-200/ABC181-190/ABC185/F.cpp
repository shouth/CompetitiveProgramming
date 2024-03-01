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
#define rall(x) rbegin(x), rend(x)

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

template<typename T>
struct fenwick_tree {
    vector<T> t;
    i64 n;

    fenwick_tree(i64 size): t(size + 1), n(size) {}

    void add(i64 i, T x) {
        for (; i <= n; i += i & -i) t[i] ^= x;
    }

    T sum(i64 i) {
        T res = 0;
        for (; i > 0; i -= i & -i) res ^= t[i];
        return res;
    }
};

void solve() {
    i64 N, Q;
    cin >> N >> Q;

    fenwick_tree<u64> t(N);
    for (i64 i = 1; i <= N; i++) {
        i64 A;
        cin >> A;
        t.add(i, A);
    }
    for (i64 i = 0; i < Q; i++) {
        i64 T, X, Y;
        cin >> T >> X >> Y;
        if (T == 1) {
            t.add(X, Y);
        } else {
            cout << (t.sum(Y) ^ t.sum(X - 1)) << "\n";
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
