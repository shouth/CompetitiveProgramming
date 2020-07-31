#include<bits/stdc++.h>
using namespace std;

using i64 = int_fast64_t;
using f64 = double;

void solve() {
    i64 n, k, s;
    cin >> n >> k >> s;
    for (i64 i = 0; i < n; i++) {
        cout << (i ? " " : "") << (i < k ? s : (s < n ? (i64) 1e9 : 1));
    }
    cout << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
