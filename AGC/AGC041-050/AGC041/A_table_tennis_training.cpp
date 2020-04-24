#include<bits/stdc++.h>
using namespace std;

using i64 = int_fast64_t;
using f64 = double;

void solve() {
    i64 n, a, b;
    cin >> n >> a >> b;
    i64 d = b - a;
    cout << (d % 2 == 0 ? d / 2 : min(n - b, a - 1) + (d + 1) / 2) << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
