#include<bits/stdc++.h>
using namespace std;

using i64 = int_fast64_t;
using f64 = double;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 n;
    cin >> n;

    i64 k = 1;
    while (k * (k + 1) < n * 2) k++;

    if (k * (k + 1) != n * 2) {
        cout << "No" << endl;
        return;
    }

    cout << "Yes" << endl;
    vector<vector<i64>> ans(k + 1, vector<i64>(k));
    for (i64 i = 0, m = 1; i < k; i++) {
        for (i64 j = i; j < k; j++, m++) {
            ans[i][j] = ans[j + 1][i] = m;
        }
    }

    cout << k + 1 << endl;
    for (auto& e : ans) {
        cout << k;
        for (auto& f : e) cout << " " << f;
        cout << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
