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
    i64 N, M;
    cin >> N >> M;

    auto update = vector(N, vector(N, false));
    auto mat = vector(N, vector(N, INF));
    auto graph = vector(M, tuple<i64, i64, i64>());
    for (auto &[ A, B, C ] : graph) {
        cin >> A >> B >> C, A--, B--;
        mat[A][B] = mat[B][A] = C;
    }

    for (i64 k = 0; k < N; k++) {
        for (i64 i = 0; i < N; i++) {
            for (i64 j = 0; j < N; j++) {
                if (mat[i][k] + mat[k][j] <= mat[i][j]) {
                    mat[i][j] = mat[i][k] + mat[k][j];
                    update[i][j] = true;
                }
            }
        }
    }

    i64 ans = 0;
    for (auto &[ A, B, C ] : graph) {
        if (update[A][B]) ans++;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
