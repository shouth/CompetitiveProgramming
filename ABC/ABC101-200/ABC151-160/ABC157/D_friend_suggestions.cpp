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

using i32 = int_fast32_t;
using i64 = int_fast64_t;

struct unionfind {
    vector<i32> p, s;

    unionfind(i32 n): p(n), s(n, 1) {
        iota(begin(p), end(p), 0);
    }

    i32 find(i32 n) {
        return p[n] == n ? n : p[n] = find(p[n]);
    }

    void unite(i32 n, i32 m) {
        n = find(n), m = find(m);
        if (n == m) return;
        if (s[n] < s[m]) swap(n, m);
        s[n] += s[m];
        p[m] = n;
    }

    i32 size(i32 n) {
        return s[find(n)];
    }

    bool same(i32 n, i32 m) {
        return find(n) == find(m);
    }
};

int main() {
    i32 n, m, k;
    cin >> n >> m >> k;
    unionfind can(n);
    vector<i32> friends(n);
    for (i32 i = 0; i < m; i++) {
        i32 a, b;
        cin >> a >> b, a--, b--;
        can.unite(a, b);
        friends[a]++, friends[b]++;
    }
    vector<i32> block(n);
    for (i32 i = 0; i < k; i++) {
        i32 c, d;
        cin >> c >> d, c--, d--;
        if (can.same(c, d)) block[c]++, block[d]++;
    }
    for (i32 i = 0; i < n; i++) {
        cout << (i == 0 ? "" : " ") << can.size(i) - friends[i] - block[i] - 1;
    }
    cout << endl;
}
