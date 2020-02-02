#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>(n, INT_MAX / 2));
    for (int i = 0; i < n; i++) adj[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t, a--, b--;
        adj[a][b] = adj[b][a] = t;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                adj[j][k] = min(adj[j][k], adj[j][i] + adj[i][k]);
            }
        }
    }

    int ans = INT_MAX;
    for (auto& e : adj) ans = min(ans, *max_element(begin(e), end(e)));
    cout << ans << endl;
}
