#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

i64 f(i64 x) {
    return x ? 1 + f(x % __builtin_popcountl(x)) : 0;
}

void solve() {
    i64 n;
    cin >> n;
    string x;
    cin >> x;
    i64 cnt = count(all(x), '1');

    if (cnt == 1) {
        for (i64 i = 0; i < n; i++) {
            cout << (x[i] == '1' ? 0 : (x[n - 1] == '1') ^ (i == n - 1) ? 2 : 1) << endl;
        }
        return;
    }

    vector<i64> modc(n), modf(n);
    i64 ci = 1, fi = 1;
    for (i64 i = 0; i < n; i++) {
        modc[n - i - 1] = ci;
        modf[n - i - 1] = fi;
        ci = (ci << 1) % (cnt + 1);
        fi = (fi << 1) % (cnt - 1);
    }

    i64 sumc = 0, sumf = 0;
    for (i64 i = 0; i < n; i++) {
        if (x[i] == '0') continue;
        sumc = (sumc + modc[i]) % (cnt + 1);
        sumf = (sumf + modf[i]) % (cnt - 1);
    }

    for (i64 i = 0; i < n; i++) {
        i64 y = x[i] == '0'
            ? (sumc + modc[i]) % (cnt + 1)
            : (sumf - modf[i] + cnt - 1) % (cnt - 1);
        cout << 1 + f(y) << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
