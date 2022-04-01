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

template<typename T = i64>
T c(i64 n, i64 k) {
    if (k < 0 || n < k) return 0;
    if (n - k < k) k = n - k;
    T res = 1;
    for (i64 i = 1; i <= k; i++) res = res * (n - i + 1) / i;
    return res;
}

void solve() {
    i64 A, B, K;
    cin >> A >> B >> K;
    for (i64 S = A + B; S > 0; S--) {
        if (i64 cnt = c(S - 1, A - 1); cnt < K) {
            cout << 'b';
            B--, K -= cnt;
        } else {
            cout << 'a';
            A--;
        }
    }
    cout << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
