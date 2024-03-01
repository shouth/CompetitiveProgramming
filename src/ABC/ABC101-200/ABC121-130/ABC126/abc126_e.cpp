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
    i32 g;

    unionfind(i32 n): p(n), s(n, 1), g(n) {
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
        p[m] = n, g--;
    }

    i32 size(i32 n) {
        return s[find(n)];
    }

    bool same(i32 n, i32 m) {
        return find(n) == find(m);
    }
};

int main() {
    i32 n, m;
    cin >> n >> m;
    unionfind t(n);
    i32 ans = 0;
    for (i32 i = 0; i < m; i++) {
        i32 x, y, z;
        cin >> x >> y >> z;
        t.unite(x, y);
    }

    cout << t.g << endl;
}
