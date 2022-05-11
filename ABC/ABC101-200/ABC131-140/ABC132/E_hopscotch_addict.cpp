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

using i32 = int_fast32_t;
using i64 = int_fast64_t;

int main() {
    i32 n, m;
    cin >> n >> m;
    vector<vector<i32>> g(n*3);
    for (i32 i = 0; i < m; i++) {
        i32 u, v;
        cin >> u >> v, u--, v--;
        for (i32 j = 0; j < 3; j++) {
            g[u*3 + j].push_back(v*3 + (j+1)%3);
        }
    }
    i32 s, t;
    cin >> s >> t, s--, t--;

    queue<i32> q;
    q.push(s*3);
    vector<i32> dist(n*3, -1);
    dist[s*3] = 0;
    while (!q.empty()) {
        i32 a = q.front(); q.pop();
        for (auto& e : g[a]) {
            if (dist[e] != -1) continue;
            dist[e] = dist[a] + 1;
            q.push(e);
        }
    }

    cout << (dist[t*3] % 3 == 0 ? dist[t*3] / 3 : -1) << endl;
}
