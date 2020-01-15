#include<bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b, a--, b--;
    int m;
    cin >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y, x--, y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    vector<int> dp(n), depth(n, -1);
    dp[a] = 1, depth[a] = 0;
    queue<int> q;
    q.push(a);
    while (!q.empty()) {
        int t = q.front(); q.pop();
        for (auto& e : graph[t]) {
            if (depth[e] == -1) {
                depth[e] = depth[t] + 1;
                q.push(e);
            }

            if (depth[e] == depth[t] + 1) {
                dp[e] += dp[t], dp[e] %= MOD;
            }
        }
    }
    cout << dp[b] << endl;
}
