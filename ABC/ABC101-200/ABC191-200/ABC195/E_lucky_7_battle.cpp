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
    i64 N;
    string S, X;
    cin >> N >> S >> X;

    auto dp = vector<i64> { 0 };
    for (i64 i = N - 1; i >= 0; i--) {
        auto next = vector<i64>();
        if (X[i] == 'T') {
            for (i64 j = 0; j < 7; j++) {
                i64 a = (j * 10) % 7, b = (a + S[i] - '0') % 7;
                if (find(all(dp), a) != dp.end() || find(all(dp), b) != dp.end()) {
                    next.emplace_back(j);
                }
            }
        } else {
            for (i64 j = 0; j < 7; j++) {
                i64 a = (j * 10) % 7, b = (a + S[i] - '0') % 7;
                if (find(all(dp), a) != dp.end() && find(all(dp), b) != dp.end()) {
                    next.emplace_back(j);
                }
            }
        }
        dp = move(next);
    }
    cout << (find(all(dp), 0) != dp.end() ? "Takahashi" : "Aoki") << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
