#include<bits/stdc++.h>
using namespace std;

using i64 = int_fast64_t;
using f64 = double;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 x;
    cin >> x;
    for (i64 a = -1000; a <= 1000; a++) {
        for (i64 b = -1000; b <= 1000; b++) {
            if ((i64) (pow(a, 5) - pow(b, 5)) == x) {
                cout << a << " " << b << endl;
                return;
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
