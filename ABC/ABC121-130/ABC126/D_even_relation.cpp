#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<pair<int64_t, int64_t>>> link(n+1);
    vector<bool> even(n+1, false), visited(n+1, false);
    for (int i=0; i<n-1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        link[u].emplace_back(v, w);
        link[v].emplace_back(u, w);
    }

    queue<pair<int64_t, int64_t>> q;
    q.emplace(1, 0);
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        visited[p.first] = true;
        if (p.second % 2 == 0) even[p.first] = true;
        for (auto e : link[p.first]) {
            if(!visited[e.first]) q.emplace(e.first, p.second + e.second);
        }
    }

    for(int i=1; i<=n; i++) {
        cout << even[i] << endl;
    }
}