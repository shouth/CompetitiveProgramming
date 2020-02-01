#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> tree;
vector<int> dist, euler, euler_dist;

void dfs(int n = 0, int d = 0) {
    dist[n] = d;
    euler.push_back(n);
    euler_dist.push_back(d);
    for (auto& e : tree[n]) {
        if (dist[e] != -1) continue;
        dfs(e, d + 1);
        euler.push_back(n);
        euler_dist.push_back(d);
    }
}

int main() {
    int n;
    cin >> n;
    tree.resize(n);
    for (int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y, x--, y--;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    dist.resize(n, -1);
    dfs();
    int m = euler_dist.size();
    vector<vector<int>> table(log2(m) + 1);
    table[0].resize(m);
    for (int i = 0; i < m; i++) {
        table[0][i] = euler_dist[i];
    }
    for (int k = 1; (1 << k) <= m; k++) {
        table[k].resize(m - (1 << k) + 1);
        for (int i = 0; i + (1 << k) <= m; i++) {
            table[k][i] = min(table[k - 1][i], table[k - 1][i + (1 << (k - 1))]);
        }
    }

    vector<int> index(n, -1);
    for (int i = 0; i < euler.size(); i++) {
        if (index[euler[i]] == -1) index[euler[i]] = i;
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b, a--, b--;
        if (index[a] > index[b]) swap(a, b);
        int k = log2(index[b] - index[a]);
        cout << dist[a] + dist[b] - min(table[k][index[a]], table[k][index[b] - (1 << k) + 1]) * 2 + 1 << endl;
    }
}
