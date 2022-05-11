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
    int64_t n;
    cin >> n;
    vector<vector<pair<int64_t, int64_t>>> t(n);
    for (int64_t i = 0; i < n - 1; i++) {
        int64_t a, b, c;
        cin >> a >> b >> c, a--, b--;
        t[a].emplace_back(b, c);
        t[b].emplace_back(a, c);
    }
    int64_t q, k;
    cin >> q >> k, k--;
    vector<int64_t> d(n, -1);
    d[k] = 0;
    queue<int64_t> p;
    p.push(k);
    while (!p.empty()) {
        int64_t tmp = p.front(); p.pop();
        for (auto& e : t[tmp]) {
            if (d[e.first] != -1) continue;
            d[e.first] = d[tmp] + e.second;
            p.push(e.first);
        }
    }

    vector<int64_t> ans(q);
    for (auto& e : ans) {
        int64_t x, y;
        cin >> x >> y, x--, y--;
        e = d[x] + d[y];
    }
    for (auto& e : ans) cout << e << endl;
}
