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
using u64 = uint_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 n, k;
    cin >> n >> k;
    vector<i64> a(n);
    for (auto& e : a) cin >> e;
    i64 asum = reduce(all(a));
    vector<i64> c(n);
    for (i64 i = 0; i < n; i++) c[i] = k * a[i] / asum;
    k -= reduce(all(c));

    auto f = [](p64 x, p64 y) { return x.first * y.second < y.first * x.second; };
    priority_queue<p64, vector<p64>, decltype(f)> q(f);
    for (i64 i = 0; i < n; i++) q.emplace(a[i], c[i] + 1);
    for (i64 i = 0; i < k; i++) {
        p64 t = q.top(); q.pop();
        t.second++;
        q.push(t);
    }

    auto& [ ansl, ansc ] = q.top();
    cout << (ansl + ansc - 1) / ansc << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
