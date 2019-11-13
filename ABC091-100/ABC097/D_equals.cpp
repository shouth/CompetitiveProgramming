#include<bits/stdc++.h>
using namespace std;

struct unionfindtree {
    vector<int> parent;

    unionfindtree(int size): parent(size) {
        iota(begin(parent), end(parent), 0);
    }

    void unite(int a, int b) {
        if ((a = find(a)) == (b = find(b))) return;
        parent[b] = a;
    }

    int find(int a) {
        return (parent[a] == a ? a : parent[a] = find(parent[a]));
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    for (auto& e : p) cin >> e;
    unionfindtree uft(n+1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        uft.unite(x, y);
    }

    int ans = 0;
    map<int, pair<vector<int>, vector<int>>> groups;
    for (int i = 0; i < n; i++) {
        int pp = uft.find(p[i]);
        groups[pp].first.push_back(p[i]);
        groups[pp].second.push_back(i+1);
    }
    for (auto& e : groups) {
        vector<int> tmp;
        sort(begin(e.second.first), end(e.second.first));
        set_intersection(begin(e.second.first), end(e.second.first), begin(e.second.second), end(e.second.second), back_inserter(tmp));
        ans += tmp.size();
    }

    cout << ans << endl;
}
