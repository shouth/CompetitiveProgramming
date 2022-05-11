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
    vector<vector<pair<int, int>>> x(n);
    for (int i = 0; i < m; i++) {
        int l, r, d;
        cin >> l >> r >> d;
        x[l-1].emplace_back(r-1, d);
        x[r-1].emplace_back(l-1, -d);
    }

    string ans = "Yes";
    vector<int> d(n, 1e9);
    for (int i = 0; i < n; i++) {
        if (d[i] != 1e9) continue;
        queue<int> q;
        q.emplace(i);
        d[i] = 0;
        while (!q.empty()) {
            int b = q.front(); q.pop();
            for (auto& e : x[b]) {
                if (d[e.first] == 1e9) {
                    q.emplace(e.first);
                    d[e.first] = d[b] + e.second;
                } else if (d[e.first] != d[b] + e.second) {
                    ans = "No";
                }
            }
        }
    }

    cout << ans << endl;
}
