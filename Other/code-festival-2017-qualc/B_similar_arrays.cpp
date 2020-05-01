#include<bits/stdc++.h>
using namespace std;

using i64 = int_fast64_t;
using f64 = double;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 n;
    cin >> n;
    i64 e = 0;
    for (i64 i = 0; i < n; i++) {
        i64 a;
        cin >> a;
        if (a % 2 == 0) e++;
    }

    cout << (i64) (pow(3, n) - pow(2, e)) << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
