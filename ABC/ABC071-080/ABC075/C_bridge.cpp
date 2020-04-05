#include<bits/stdc++.h>
using namespace std;

struct unionfindtree {
    vector<int> parent;
    int group;
    unionfindtree(int size): parent(size+1), group(size) {
        iota(begin(parent), end(parent), 0);
    }
    int find(int n) {
        return parent[n] == n ? n : parent[n] = find(parent[n]);
    }
    void unite(int n, int m) {
        n = find(n);
        m = find(m);
        if (n != m) {
            group--;
            parent[n] = m;
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> ab(m);
    for (auto& e : ab) cin >> e.first >> e.second;
    
    int ans = 0;
    for (int i = 0; i < m; i++) {
        unionfindtree uft(n);
        for (int j = 0; j < m; j++) {
            if (j == i) continue;
            uft.unite(ab[j].first, ab[j].second);
        }
        if (uft.group != 1) ans++;
    }

    cout << ans << endl;
}
