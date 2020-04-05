#include <bits/stdc++.h>
using namespace std;

struct uftree {
    vector<int64_t> par, height, size;

    uftree(int64_t n): par(n), height(n, 0), size(n, 1) {
        for(int64_t i = 0; i < n; i++) par[i] = i;
    }

    int64_t find(int64_t x) {
        return par[x] == x ? x : par[x] = find(par[x]);
    }

    void unite(int64_t x, int64_t y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (height[x] < height[y]) {
            par[x] = y;
            size[y] += size[x];
        } else {
            par[y] = x;
            size[x] += size[y];
            if(height[x] == height[y]) height[x]++;
        }
    }

    bool issame(int64_t x, int64_t y) {
        return find(x) == find(y);
    }

    int64_t treesize(int64_t x) {
        return size[find(x)];
    }    
};

int main() {
    int64_t n, m;
    cin >> n >> m;
    vector<pair<int64_t, int64_t>> ab(m);
    for(auto& e : ab) {
        cin >> e.first >> e.second;
        e.first--;
        e.second--;
    }
    uftree t(n);
    vector<int64_t> ans(m);
    ans[m-1] = n * (n - 1) / 2;
    for(size_t i = m - 1; i > 0; i--) {
        ans[i-1] = ans[i] - (t.issame(ab[i].first, ab[i].second) ? 0 : t.treesize(ab[i].first) * t.treesize(ab[i].second));
        t.unite(ab[i].first, ab[i].second);
    }
    for(size_t i = 0; i < m; i++) {
        cout << ans[i] << endl;
    }
}