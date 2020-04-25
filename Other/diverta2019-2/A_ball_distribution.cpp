#include<bits/stdc++.h>
using namespace std;

using i64 = int_fast64_t;
using f64 = double;

void solve() {
    i64 n, k;
    cin >> n >> k;
    cout << (k == 1 ? 0 : n - k) << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
