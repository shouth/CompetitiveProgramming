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

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> original(n, vector<int>(n, 1e9)), adj;
    vector<pair<int, int>> edge;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c, a--, b--;
        original[a][b] = original[b][a] = c;
        edge.emplace_back(a, b);
    }
    adj = original;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                adj[j][k] = min(adj[j][k], adj[j][i] + adj[i][k]);
            }
        }
    }

    int ans = 0;
    for (auto& e : edge) {
        if (original[e.first][e.second] != adj[e.first][e.second]) ans++;
    }
    cout << ans << endl;
}
