#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

template<typename T>
struct bit {
    vector<T> t;
    i64 size;

    bit(i64 n): t(n + 1), size(n + 1) {}

    void add(i64 i, T x) {
        for (; i <= size; i += i & -i) t[i] += x;
    }

    T sum(i64 i) {
        T res = 0;
        for (; i > 0; i -= i & -i) res += t[i];
        return res;
    }
};

void solve() {
    i64 q;
    cin >> q;

    i64 n = 200010;
    bit<i64> b(n);
    for (i64 i = 0; i < q; i++) {
        i64 t, x;
        cin >> t >> x;

        if (t == 1) {
            b.add(x, 1);
        } else {
            i64 l = -1, r = n;
            while (abs(r - l) > 1) {
                i64 m = (l + r) / 2;
                (b.sum(m) < x ? l : r) = m;
            }
            cout << r << endl;
            b.add(r, -1);
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
