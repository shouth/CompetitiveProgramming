#include<bits/stdc++.h>
using namespace std;

struct unionfindtree {
    vector<int> parent;

    unionfindtree(int n): parent(n) {
        iota(begin(parent), end(parent), 0);
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        parent[find(x)] = find(y);
    }
};

int main() {
    int n, k, l;
    cin >> n >> k >> l;

    unionfindtree roadtree(n), railtree(n);
    for (int i = 0; i < k; i++) {
        int p, q;
        cin >> p >> q, p--, q--;
        roadtree.unite(p, q);
    }
    for (int i = 0; i < l; i++) {
        int r, s;
        cin >> r >> s, r--, s--;
        railtree.unite(r, s);
    }

    map<int, vector<int>> roadcity;
    for (int i = 0; i < n; i++) roadcity[roadtree.find(i)].push_back(i);

    vector<int> ans(n);
    for (auto& rc : roadcity) {
        map<int, int> tmp;
        for (auto& e : rc.second) tmp[railtree.find(e)]++;
        for (auto& e : rc.second) ans[e] = tmp[railtree.find(e)];
    }
    for (auto& e : ans) cout << e << endl;
}
