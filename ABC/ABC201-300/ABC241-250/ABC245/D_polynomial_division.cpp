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
    i64 N, M;
    cin >> N >> M;
    auto A = vector<i64>(N + 1);
    for (auto& e : A) cin >> e;
    auto C = vector<i64>(N + M + 1);
    for (auto& e : C) cin >> e;

    i64 z = 0;
    for (i64 i = 0; i <= N; i++) {
        if (A[i] != 0) {
            z = i;
            break;
        }
    }

    auto B = vector<i64>(M + 1);
    for (i64 i = z; i - z <= M; i++) {
        i64 AB = 0;
        for (i64 j = 0; j <= M; j++) {
            if (i - j > z && i - j <= N) AB += A[i - j] * B[j];
        }
        B[i - z] = (C[i] - AB) / A[z];
    }
    for (i64 i = 0; i <= M; i++) {
        cout << (i ? " " : "") << B[i];
    }
    cout << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
