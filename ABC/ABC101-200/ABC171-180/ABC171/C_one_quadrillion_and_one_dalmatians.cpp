#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 n;
    cin >> n;

    i64 d = 1;
    for (i64 i = 26; n > i; i *= 26) n -= i, d++;

    n--;
    string ans(d, 'a');
    for (i64 i = d - 1; n > 0; i--) {
        ans[i] += n % 26;
        n /= 26;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
