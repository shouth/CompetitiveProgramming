#include<bits/stdc++.h>
using namespace std;

using i64 = int_fast64_t;
using f64 = double;

void solve() {
    i64 h, w, n;
    cin >> h >> w >> n;
    i64 p = max(h, w);
    cout << (n + p - 1) / p << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
