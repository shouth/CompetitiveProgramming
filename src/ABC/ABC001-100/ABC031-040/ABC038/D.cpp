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

constexpr int INF = 1e9;

struct bit {
    int64_t size;
    vector<int64_t> v;

    bit(int64_t n): size(n+1), v(size) {}

    void update(int64_t a, int64_t w) {
        for (int64_t x = a; x <= size; x += x & -x) v[x] = max(w, v[x]);
    }

    int query(int64_t a) {
        int64_t res = 0;
        for (int64_t x = a; x > 0; x -= x & -x) res = max(res, v[x]);
        return res;
    }
};

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> wh(n);
    int maxh = 0;
    for (auto& e : wh) cin >> e.first >> e.second, maxh = max(maxh, e.second);
    sort(begin(wh), end(wh), [](auto a, auto b) {
        return a.first != b.first ? a.first < b.first : a.second > b.second;
    });

    bit b(maxh);
    for (auto& e : wh) b.update(e.second, b.query(e.second - 1) + 1);

    cout << b.query(maxh) << endl;
}
