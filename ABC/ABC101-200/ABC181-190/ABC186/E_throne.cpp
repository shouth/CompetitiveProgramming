#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

struct extended_gcd_solution {
    i64 x, y, gcd;
};

extended_gcd_solution extended_gcd(i64 a, i64 b) {
    i64 sa = 1, sb = 0;
    i64 ta = 0, tb = 1;

    while (true) {
        i64 q = a / b;
        i64 r = a % b;
        a = b, b = r;
        i64 sc = sa - q * sb;
        i64 tc = ta - q * tb;
        sa = sb, sb = sc;
        ta = tb, tb = tc;
        if (r == 0) return { sa, ta, a };
    }
}

void solve() {
    i64 T;
    cin >> T;

    for (i64 i = 0; i < T; i++) {
        i64 N, S, K;
        cin >> N >> S >> K;

        auto [ x, y, gcd ] = extended_gcd(K, N);
        S = N - S;

        if (S % gcd != 0) {
            cout << -1 << endl;
            continue;
        }

        N /= gcd, S /= gcd, K /= gcd;
        cout << (x * S % N + N) % N << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}