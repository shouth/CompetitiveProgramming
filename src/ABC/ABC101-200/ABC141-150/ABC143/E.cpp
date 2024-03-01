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
    i64 N, M, L;
    cin >> N >> M >> L;

    auto mat = vector(N, vector(N, INF));
    for (i64 i = 0; i < N; i++) {
        mat[i][i] = 0;
    }
    for (i64 i = 0; i < M; i++) {
        i64 A, B, C;
        cin >> A >> B >> C, A--, B--;
        mat[A][B] = mat[B][A] = C;
    }
    for (i64 i = 0; i < N; i++) {
        for (i64 j = 0; j < N; j++) {
            for (i64 k = 0; k < N; k++) {
                mat[j][k] = min(mat[j][k], mat[j][i] + mat[i][k]);
            }
        }
    }

    for (i64 i = 0; i < N; i++) {
        for (i64 j = 0; j < N; j++) {
            mat[i][j] = i == j ? 0 : mat[i][j] > L ? INF : 1;
        }
    }
    for (i64 i = 0; i < N; i++) {
        for (i64 j = 0; j < N; j++) {
            for (i64 k = 0; k < N; k++) {
                mat[j][k] = min(mat[j][k], mat[j][i] + mat[i][k]);
            }
        }
    }

    i64 Q;
    cin >> Q;
    for (i64 i = 0; i < Q; i++) {
        i64 s, t;
        cin >> s >> t, s--, t--;
        cout << (mat[s][t] < INF ? mat[s][t] - 1 : -1) << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
