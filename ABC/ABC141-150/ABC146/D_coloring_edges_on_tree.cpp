#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> tree(n);
    vector<pair<int, int>> ab(n-1);
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b, a--, b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
        ab[i] = make_pair(a, b);
    }

    vector<int> derivec(n);
    vector<int> visit(n);
    map<pair<int, int>, int> mapc;
    int cnum = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int tmp = q.front(); q.pop();
        visit[tmp] = true;
        if (cnum < (int) tree[tmp].size()) cnum = tree[tmp].size();

        int color = 1;
        for (auto& e : tree[tmp]) {
            if (visit[e]) continue;
            if (derivec[tmp] == color) color++;
            derivec[e] = mapc[make_pair(tmp, e)] = mapc[make_pair(e, tmp)] = color++;
            q.push(e);
        }
    }

    cout << cnum << endl;
    for (auto& e : ab) cout << mapc[e] << endl;
}
