#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    string x;
    cin >> x;

    i64 s = 0, t = 0;
    for (auto& e : x) {
        if (e == 'S') {
            s++;
        } else if (s == 0) {
            t++;
        } else {
            s--;
        }
    }

    cout << s + t << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
