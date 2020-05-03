#include<bits/stdc++.h>
using namespace std;

using i64 = int_fast64_t;
using f64 = double;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 n, a, b, c, d;
    cin >> n >> a >> b >> c >> d, a--, b--, c--, d--;
    string s;
    cin >> s;

    if (s.substr(a, c - a + 1).find("##") != string::npos
        || s.substr(b, d - b + 1).find("##") != string::npos) {
        cout << "No" << endl;
    } else if (c < d) {
        cout << "Yes" << endl;
    } else if (s.substr(b - 1, d - b + 3).find("...") != string::npos) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
