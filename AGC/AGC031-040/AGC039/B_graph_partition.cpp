#include<bits/stdc++.h>
using namespace std;

using i64 = int_fast64_t;
using f64 = double;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 n;
    cin >> n;
    vector<vector<i64>> mat(n, vector<i64>(n, INF));
    for (i64 i = 0; i < n; i++) {
        for (i64 j = 0; j < n; j++) {
            char c;
            cin >> c;
            if (i == j) mat[i][j] = 0;
            if (c == '1') mat[i][j] = 1;
        }
    }

    vector<i64> b(n, -1);
    b[0] = 0;
    queue<i64> q;
    q.push(0);
    while (!q.empty()) {
        i64 t = q.front(); q.pop();
        for (i64 i = 0; i < n; i++) {
            if (t == i) continue;
            if (mat[t][i] == INF) continue;
            if (b[i] != -1) {
                if (b[t] ^ b[i]) continue;
                cout << -1 << endl;
                return;
            }
            b[i] = !b[t];
            q.push(i);
        }
    }

    for (i64 i = 0; i < n; i++) {
        for (i64 j = 0; j < n; j++) {
            for (i64 k = 0; k < n; k++) {
                mat[j][k] = min(mat[j][k], mat[j][i] + mat[i][k]);
            }
        }
    }

    i64 ans = 0;
    for (auto& e : mat) {
        for (auto& f : e) {
            ans = max(ans, f);
        }
    }

    cout << ans + 1 << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
