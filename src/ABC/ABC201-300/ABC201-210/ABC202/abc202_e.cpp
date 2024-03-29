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
    auto tree = vector<vector<i64>>(N);
    for (i64 p = 0; p < N - 1; p++) {
        i64 P;
        cin >> P, P--;
        tree[p].emplace_back(P);
    }

    auto dists = vector<i64>(N, -1);
    dists[0] = 0;
    auto q = queue<i64>();
    q.emplace(0);
    while (!q.empty()) {
        i64 node = q.front();
        q.pop();

        for (auto &next : tree[node]) {
            if (dists[next] != -1) continue;
            dists[next] = dists[node] + 1;
            q.emplace(next);
        }
    }

    i64 Q;
    cin >> Q;
    for (i64 _ = 0; _ < Q; _++) {
        i64 U, D;
        cin >> U >> D, U--;


    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
