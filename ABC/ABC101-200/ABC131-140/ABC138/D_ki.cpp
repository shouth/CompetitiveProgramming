#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> ab(n-1);
    for (auto& e : ab) cin >> e.first >> e.second;
    vector<pair<int, int>> px(q);
    for (auto& e : px) cin >> e.first >> e.second;

    vector<vector<int>> c(n+1);
    for (auto e : ab) {
        c[e.first].push_back(e.second);
        c[e.second].push_back(e.first);
    }

    vector<bool> visited(n+1, false);
    vector<int> values(n+1, 0);
    for (auto e : px) values[e.first] += e.second;
    queue<int> nexts;
    nexts.push(1);
    while (!nexts.empty()) {
        int next = nexts.front(); nexts.pop();
        for (auto e : c[next]) {
            if (!visited[e]) {
                values[e] += values[next];
                nexts.push(e);
            }
        }
        visited[next] = true;
    }

    for (int i = 1; i <= n; i++) cout << values[i] << " ";
}
