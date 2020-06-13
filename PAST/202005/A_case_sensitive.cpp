#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    string s, t;
    cin >> s >> t;
    if (s == t) {
        cout << "same" << endl;
        return;
    }

    transform(all(s), begin(s), ::tolower);
    transform(all(t), begin(t), ::tolower);

    if (s == t) {
        cout << "case-insensitive" << endl;
        return;
    }

    cout << "different" << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
