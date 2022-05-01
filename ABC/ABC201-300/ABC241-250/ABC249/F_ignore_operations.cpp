#include<bits/stdc++.h>
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
    i64 N, K;
    cin >> N >> K;
    auto ty = vector<p64>(N + 1);
    ty[N] = { 1, 0 };
    for (i64 i = N - 1; i >= 0; i--) {
        auto &[ t, y ] = ty[i];
        cin >> t >> y;
    }

    auto neg = priority_queue<i64>();
    i64 ans = -INF;
    i64 cand = 0;
    for (auto [ t, y ] : ty) {
        if (t == 1) {
            ans = max(ans, cand + y);
            if (--K < 0) break;
            if ((i64) neg.size() > K) {
                cand += neg.top();
                neg.pop();
            }
        } else {
            if (y >= 0) {
                cand += y;
            } else {
                neg.emplace(y);
                if ((i64) neg.size() > K) {
                    cand += neg.top();
                    neg.pop();
                }
            }
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
