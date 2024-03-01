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

struct unionfindtree {
    vector<int> parent, size;

    unionfindtree(int n): parent(n), size(n, 1) {
        iota(begin(parent), end(parent), 0);
    }

    int find(int n) {
        return parent[n] == n ? n : parent[n] = find(parent[n]);
    }

    void unite(int n, int m) {
        n = find(n), m = find(m);
        if (n == m) return;
        parent[n] = m;
        size[m] += size[n];
    }

    int treesize(int n) {
        return size[find(n)];
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> yab;
    for (int i = 0; i < m; i++) {
        int a, b, y;
        cin >> a >> b >> y, a--, b--;
        yab.emplace_back(y, a, b);
    }
    sort(begin(yab), end(yab), greater<>());

    int q;
    cin >> q;
    vector<tuple<int, int, int>> wvj;
    for (int i = 0; i < q; i++) {
        int v, w;
        cin >> v >> w, v--;
        wvj.emplace_back(w, v, i);
    }
    sort(begin(wvj), end(wvj), greater<>());

    unionfindtree road(n);
    vector<int> ans(q);
    int ri = 0;
    for (auto& e : wvj) {
        int w, v, j;
        tie(w, v, j) = e;

        while (ri < m && w < get<0>(yab[ri])) {
            int a, b;
            tie(ignore, a, b) = yab[ri++];
            road.unite(a, b);
        }

        ans[j] = road.treesize(v);
    }

    for (auto& e : ans) cout << e << endl;
}
