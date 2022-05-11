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

    bool unite(i64 n, i64 m) {
        n = find(n), m = find(m);
        if (n == m) return false;
        if (s[n] < s[m]) swap(n, m);
        s[n] += s[m];
        p[m] = n;
        return true;
    }

    i64 size(i64 n) {
        return s[find(n)];
    }

    bool same(i64 n, i64 m) {
        return find(n) == find(m);
    }
};

void solve() {
    i64 N, Q;
    cin >> N >> Q;
    vector<map<i64, i64>> cnts(N);
    for (auto& cnt : cnts) {
        i64 C;
        cin >> C, C--;
        cnt[C]++;
    }

    union_find_tree t(N);
    for (i64 i = 0; i < Q; i++) {
        i64 q;
        cin >> q;
        if (q == 1) {
            i64 a, b;
            cin >> a >> b, a--, b--;
            if (t.same(a, b)) continue;
            a = t.find(a), b = t.find(b);
            if (t.size(a) < t.size(b)) {
                for (auto& [ k, v ] : cnts[a]) cnts[b][k] += v;
            } else {
                for (auto& [ k, v ] : cnts[b]) cnts[a][k] += v;
            }
            t.unite(a, b);
        } else {
            i64 x, y;
            cin >> x >> y, x--, y--;
            cout << cnts[t.find(x)][y] << "\n";
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
