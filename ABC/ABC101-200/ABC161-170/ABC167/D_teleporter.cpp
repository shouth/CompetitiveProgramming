#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using f64 = double;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 n, k;
    cin >> n >> k;
    vector<i64> as(n);
    for (auto& e : as) cin >> e, e--;
    vector<i64> path;
    vector<i64> visited(n);

    i64 a = 0;
    for (; k > 0; k--) {
        if (visited[a]) break;
        visited[a] = 1;
        path.emplace_back(a);
        a = as[a];
    }

    if (k == 0) {
        cout << a + 1 << endl;
        return;
    }

    i64 idx = find(all(path), a) - begin(path);
    k %= path.size() - idx;
    cout << path[idx + k] + 1 << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
