#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 N, P;
    cin >> N >> P;
    string S;
    cin >> S;

    if (P == 2 || P == 5) {
        i64 ans = 0;
        for (i64 i = 0; i < N; i++) {
            if ((S[i] - '0') % P == 0) ans += i + 1;
        }
        cout << ans << endl;
        return;
    }

    reverse(all(S));
    vector<i64> cnt(P);
    i64 rem = 0, digit = 1;
    cnt[rem]++;
    for (auto& e : S) {
        rem = (rem + digit * (e - '0')) % P;
        cnt[rem]++;
        digit = digit * 10 % P;
    }

    i64 ans = 0;
    for (auto& e : cnt) {
        ans += e * (e - 1) / 2;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
