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
    auto A = vector<i64>(N);
    for (auto &e : A) cin >> e;
    auto B = vector<i64>(N);
    for (auto &e : B) cin >> e;

    for (i64 i = 0; i + 1 < N; i++) {
        if (abs(A[i] - A[i + 1]) > K && abs(B[i] - A[i + 1]) > K) {
            A[i + 1] = INF;
        }
        if (abs(A[i] - B[i + 1]) > K && abs(B[i] - B[i + 1]) > K) {
            B[i + 1] = INF;
        }
    }
    cout << Yes(A.back() != INF || B.back() != INF) << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
