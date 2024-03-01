#include <utility>
#include <bitset>
#include <tuple>
#include <string>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <complex>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

struct edge { int to, cap, rev; };

vector<vector<edge>> graph;
vector<bool> used;

void add_edge(int from, int to, int cap) {
    graph[from].push_back({to, cap, graph[to].size()});
    graph[to].push_back({from, 0, graph[from].size()-1});
}


int dfs(int v, int t, int f) {
    if (v == t) return f;
    used[v] = true;
    for (auto& e : graph[v]) {
        if (!used[e.to] && e.cap > 0) {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                graph[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t) {
    int flow = 0;
    while (true) {
        fill(begin(used), end(used), false);
        int f = dfs(s, t, INT_MAX);
        if (f == 0) return flow;
        flow += f;
    }
}

int main() {
    int n, g, e;
    cin >> n >> g >> e;
    graph.resize(n+1);
    used.resize(n+1);
    for (int i = 0; i < g; i++) {
        int p;
        cin >> p;
        add_edge(p, n, 1);
        add_edge(n, p, 1);
    }
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        add_edge(a, b, 1);
        add_edge(b, a, 1);
    }

    cout << max_flow(0, n) << endl;
}
