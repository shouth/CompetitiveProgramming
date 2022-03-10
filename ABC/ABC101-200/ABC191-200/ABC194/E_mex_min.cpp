#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define yes(x) ((x) ? "yes" : "no")
#define Yes(x) ((x) ? "Yes" : "No")

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 N, M;
    cin >> N >> M;

    auto pos = vector<vector<i64>>(N);
    for (i64 i = 0; i < N; i++) {
        i64 A;
        cin >> A;
        pos[A].push_back(i);
    }

    for (i64 i = 0; i < N; i++) {
        if (pos[i].empty() || pos[i].front() + 1 > M || N - pos[i].back() > M) {
            cout << i << endl;
            return;
        }
        for (i64 j = 0; j + 1 < (i64) pos[i].size(); j++) {
            if (pos[i][j + 1] - pos[i][j] > M) {
                cout << i << endl;
                return;
            }
        }
    }

    cout << N << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
