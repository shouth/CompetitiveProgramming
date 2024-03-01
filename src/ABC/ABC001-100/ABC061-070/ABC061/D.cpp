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

constexpr int64_t INF = 1e18;

int main() {
    int64_t n, m;
    cin >> n >> m;
    vector<tuple<int64_t, int64_t, int64_t>> abc;
    for (int64_t i = 0; i < m; i++) {
        int64_t a, b, c;
        cin >> a >> b >> c;
        abc.emplace_back(a, b, c);
    }

    vector<int64_t> d(n+1, -INF);
    d[1] = 0;
    for (int64_t i = 0; i < n-1; i++) {
        for (auto& e : abc) {
            int64_t a, b, c;
            tie(a, b, c) = e;
            if (d[a] == -INF) continue;
            if (d[b] < d[a] + c) d[b] = d[a] + c;
        }
    }

    int64_t ans = d[n];
    bitset<1010> cycle;
    for (int64_t i = 0; i < n; i++) {
        for (auto& e : abc) {
            int64_t a, b, c;
            tie(a, b, c) = e;
            if (d[a] == -INF) continue;
            if (d[b] < d[a] + c) d[b] = d[a] + c, cycle[b] = true;
            if (cycle[a]) cycle[b] = true;
        }
    }

    if (cycle[n]) cout << "inf" << endl;
    else cout << ans << endl;
}
