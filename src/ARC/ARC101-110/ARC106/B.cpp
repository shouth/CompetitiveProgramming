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

struct union_find_tree {
    vector<i64> p, s;

    union_find_tree(i64 n): p(n), s(n, 1) {
        iota(begin(p), end(p), 0);
    }

    i64 find(i64 n) {
        return p[n] == n ? n : p[n] = find(p[n]);
    }

    void unite(i64 n, i64 m) {
        n = find(n), m = find(m);
        if (n == m) return;
        if (s[n] < s[m]) swap(n, m);
        s[n] += s[m];
        p[m] = n;
    }

    i64 size(i64 n) {
        return s[find(n)];
    }

    bool same(i64 n, i64 m) {
        return find(n) == find(m);
    }
};

void solve() {
    i64 N, M;
    cin >> N >> M;

    vector<i64> a(N), b(N);
    for (auto& e : a) cin >> e;
    for (auto& e : b) cin >> e;

    union_find_tree t(N);
    for (i64 i = 0; i < M; i++) {
        i64 c, d;
        cin >> c >> d, c--, d--;
        t.unite(c, d);
    }

    vector<i64> acnt(N), bcnt(N);
    for (i64 i = 0; i < N; i++) {
        acnt[t.find(i)] += a[i];
        bcnt[t.find(i)] += b[i];
    }

    bool flag = true;
    for (i64 i = 0; i < N; i++) {
        flag &= acnt[i] == bcnt[i];
    }
    cout << (flag ? "Yes" : "No") << "\n";
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
