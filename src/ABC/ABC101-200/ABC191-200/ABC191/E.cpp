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

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define yes(x) ((x) ? "yes" : "no")
#define Yes(x) ((x) ? "Yes" : "No")

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

vector<i64> dijkstra(vector<vector<p64>> &graph, i64 start) {
    i64 n = graph.size();
    vector<i64> dists(n, -1);
    priority_queue<p64, vector<p64>, greater<>> pq;
    pq.emplace(0, start);
    while (!pq.empty()) {
        auto [ distsum, cur ] = pq.top();
        pq.pop();
        if (dists[cur] != -1) continue;
        dists[cur] = distsum;
        for (auto& [ dist, nxt ] : graph[cur]) {
            if (dists[nxt] != -1) continue;
            pq.emplace(dists[cur] + dist, nxt);
        }
    }
    return dists;
}

void solve() {
    i64 N, M;
    cin >> N >> M;

    vector<vector<p64>> forg(N), backg(N);
    vector<i64> self(N, INF);
    for (i64 i = 0; i < M; i++) {
        i64 A, B, C;
        cin >> A >> B >> C, A--, B--;
        forg[A].emplace_back(C, B);
        backg[B].emplace_back(C, A);
        if (A == B) self[A] = min(self[A], C);
    }

    for (i64 i = 0; i < N; i++) {
        i64 ans = self[i];
        vector<i64> fordists = dijkstra(forg, i);
        vector<i64> backdists = dijkstra(backg, i);

        for (i64 j = 0; j < N; j++) {
            if (i == j || fordists[j] == -1 || backdists[j] == -1) continue;
            ans = min(ans, fordists[j] + backdists[j]);
        }
        cout << (ans < INF ? ans : -1) << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
