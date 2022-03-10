#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define yes(x) ((x) ? "yes" : "no")
#define Yes(x) ((x) ? "Yes" : "No")

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

template<typename T>
class fenwick_tree {
    vector<T> t;
    i64 n;

public:
    fenwick_tree(i64 size): t(size + 1), n(size + 1) {}

    void add(i64 i, T x) {
        for (; i <= n; i += i & -i) t[i] += x;
    }

    T sum(i64 i) {
        T res = 0;
        for (; i > 0; i -= i & -i) res += t[i];
        return res;
    }
};

void solve() {
    i64 N;
    cin >> N;
    vector<i64> a(N);
    for (auto& e : a) cin >> e, e++;

    fenwick_tree<i64> ft(N);
    i64 ans = 0;
    for (i64 i = N - 1; i >= 0; i--) {
        ans += ft.sum(a[i]);
        ft.add(a[i], 1);
    }

    for (auto& e : a) {
        cout << ans << "\n";
        ans -= e - 1;
        ans += N - e;
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
