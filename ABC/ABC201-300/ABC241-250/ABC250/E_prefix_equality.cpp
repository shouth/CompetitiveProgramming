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

#include<atcoder/all>

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define yes(x) ((x) ? "yes" : "no")
#define Yes(x) ((x) ? "Yes" : "No")

using namespace std;
using namespace atcoder;

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;
using m64 = modint1000000007;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 N;
    cin >> N;
    auto a = vector<i64>(N);
    for (auto &e : a) cin >> e;
    auto b = vector<i64>(N);
    for (auto &e : b) cin >> e;

    i64 cnt = 1;
    auto m = map<i64, i64>();
    auto f = [&](vector<i64> &v) {
        for (auto &e : v) {
            if (m.find(e) == m.end()) {
                m[e] = cnt++;
            }
            e = m[e];
        }
    };
    auto g = [&](vector<i64> &v) {
        auto s = set<i64>();
        for (auto &e : v) {
            s.emplace(e);
            e = (i64) s.size();
        }
    };
    f(a);
    g(a);

    f(b);
    auto c = vector<i64>(N);
    c[0] = b[0];
    for (i64 i = 1; i < N; i++) {
        c[i] = max(b[i], c[i - 1]);
    }
    g(b);

    i64 Q;
    cin >> Q;
    for (i64 _ = 0; _ < Q; _++) {
        i64 x, y;
        cin >> x >> y, x--, y--;
        cout << Yes(a[x] == b[y] && b[y] == c[y]) << "\n";
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
