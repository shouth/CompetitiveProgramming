#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 N;
    cin >> N;
    vector<double> x(N);
    for (auto& e : x) cin >> e;

    double a = 0;
    for (auto& e : x) a += abs(e);
    double b = 0;
    for (auto& e : x) b += e * e;
    b = sqrt(b);
    double c = 0;
    for (auto& e : x) c = max(c, abs(e));
    cout << a << "\n" << b << "\n" << c << endl;;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
