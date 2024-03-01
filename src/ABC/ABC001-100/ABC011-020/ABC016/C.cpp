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
    vector<vector<int>> dist(n, vector<int>(n, 1000));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b, a--, b--;
        dist[a][b] = dist[b][a] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (j != k) dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int ans = 0;
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == 2) ans++;
        }
        cout << ans << endl;
    }
}
