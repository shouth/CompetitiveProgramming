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

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

constexpr p64 operator+(p64 x, p64 y) { return { x.first + y.first, x.second + y.second }; }

void solve() {
    i64 k;
    cin >> k;
    string s;
    cin >> s;

    string dirs = "LRUD";
    p64 cur = { 0, 0 };
    map<p64, map<char, p64>> edge;
    edge[cur]['L'] = edge[cur]['R'] = edge[cur]['U'] = edge[cur]['D'] = cur;
    map<char, p64> dxy;
    dxy['L'] = { -1, 0 }, dxy['R'] = { 1, 0 }, dxy['U'] = { 0, 1 }, dxy['D'] = { 0, -1 };
    map<char, char> rdirs;
    rdirs['L'] = 'R', rdirs['R'] = 'L', rdirs['U'] = 'D', rdirs['D'] = 'U';
    for (auto& e : s) {
        cur = edge[cur][e] + dxy[e];
        for (auto& d : dirs) {
            p64 nxt = cur + dxy[d];
            edge[cur][d] = edge.find(nxt) == edge.end() ? cur : edge[nxt][d];
        }
        for (auto& d : dirs) {
            p64 nxt = cur + dxy[d];
            if (edge.find(nxt) == edge.end()) continue;
            p64 nedge = edge[nxt][d];
            edge[nedge][rdirs[d]] = edge[cur][rdirs[d]];
        }
    }

    auto [ x, y ] = cur;
    cout << x << " " << y << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
