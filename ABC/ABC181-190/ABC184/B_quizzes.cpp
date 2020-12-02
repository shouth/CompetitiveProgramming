#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 N, X;
    cin >> N >> X;
    for (i64 i = 0; i < N; i++) {
        char s;
        cin >> s;
        if (s == 'o') {
            X++;
        } else {
            if (X > 0) X--;
        }
    }
    cout << X << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}