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

struct unionfindtree {
    vector<int> parent;
    int group;

    unionfindtree(int size): parent(size), group(size) {
        iota(begin(parent), end(parent), 0);
    }

    int find(int n) {
        return parent[n] == n ? n : parent[n] = find(parent[n]);
    }

    void unite(int n, int m) {
        n = find(n), m = find(m);
        parent[n] = m;
        if (n != m) group--;
    }

    bool unified() {
        return group == 1;
    }

    bool issame(int n, int m) {
        return find(n) == find(m);
    }
};

int main() {
    int64_t n;
    cin >> n;
    vector<pair<int64_t, int64_t>> x, y;
    for (int64_t i = 0; i < n; i++) {
        int xx, yy;
        cin >> xx >> yy;
        x.emplace_back(xx, i);
        y.emplace_back(yy, i);
    }
    sort(begin(x), end(x));
    sort(begin(y), end(y));

    using tuple3 = tuple<int64_t, int64_t, int64_t>;
    priority_queue<tuple3, vector<tuple3>, greater<tuple3>> pq;
    for (int i = 0; i + 1 < n; i++) {
        pq.emplace(x[i+1].first - x[i].first, x[i].second, x[i+1].second);
        pq.emplace(y[i+1].first - y[i].first, y[i].second, y[i+1].second);
    }

    unionfindtree uft(n);
    int64_t ans = 0;
    while (!uft.unified()) {
        int64_t d, a, b;
        tie(d, a, b) = pq.top(); pq.pop();
        if (!uft.issame(a, b)) {
            ans += d;
            uft.unite(a, b);
        }
    }

    cout << ans << endl;
}
