#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 n;
    cin >> n;
    map<string, i64> cnt;
    for (i64 i = 0; i < n; i++) {
        string s;
        cin >> s;
        cnt[s]++;
    }

    cout << "AC" << " x " << cnt["AC"] << endl;
    cout << "WA" << " x " << cnt["WA"] << endl;
    cout << "TLE" << " x " << cnt["TLE"] << endl;
    cout << "RE" << " x " << cnt["RE"] << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
