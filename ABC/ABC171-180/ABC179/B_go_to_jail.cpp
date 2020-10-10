#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 N;
    cin >> N;
    vector<p64> D(N);
    for (auto& [ D1, D2 ] : D) cin >> D1 >> D2;
    for (i64 i = 0; i + 2 < N; i++) {
        bool flag = true;
        for (i64 j = 0; j < 3; j++) flag &= D[i + j].first == D[i + j].second;
        if (flag) {
            cout << "Yes" << endl;
            return;
        }
    }

    cout << "No" << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
