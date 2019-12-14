#include<bits/stdc++.h>
using namespace std;

using pint = pair<int64_t, int64_t>;

vector<int64_t> daijkstra(const vector<vector<pint>>& graph) {
    vector<int64_t> dist(graph.size(), -1);
    priority_queue<pint, vector<pint>, greater<pint>> pq;
    pq.emplace(0, 0);
    while (!pq.empty()) {
        int64_t cost, city;
        tie(cost, city) = pq.top(); pq.pop();
        if (dist[city] != -1) continue;
        dist[city] = cost;
        for (const auto& e : graph[city]) {
            if (dist[e.second] != -1 && dist[e.second] <= cost + e.first) continue;
            pq.emplace(cost + e.first, e.second);
        }
    }
    return dist;
}

int main() {
    int64_t n, m, t;
    cin >> n >> m >> t;
    vector<int64_t> a(n);
    for (auto& e : a) cin >> e;
    vector<vector<pint>> forg(n), invg(n);
    for (int64_t i = 0; i < m; i++) {
        int64_t at, bt, cost;
        cin >> at >> bt >> cost, at--, bt--;
        forg[at].emplace_back(cost, bt);
        invg[bt].emplace_back(cost, at);
    }

    vector<int64_t> totime = daijkstra(forg), fromtime = daijkstra(invg);
    int64_t ans = 0;
    for (int64_t i = 0; i < n; i++) {
        if (totime[i] == -1 || fromtime[i] == -1) continue;
        int64_t stay = t - (totime[i] + fromtime[i]);
        ans = max(ans, stay * a[i]);
    }
    cout << ans << endl;
}
