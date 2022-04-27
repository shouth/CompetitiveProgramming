#include<bits/stdc++.h>
#include<atcoder/all>

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define yes(x) ((x) ? "yes" : "no")
#define Yes(x) ((x) ? "Yes" : "No")

using namespace std;
using namespace atcoder;

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;
using m64 = modint1000000007;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    string S;
    cin >> S;

    bool upper = false;
    bool lawer = false;
    bool unique = true;
    auto used = set<char>();
    for (auto &e : S) {
        upper |= isupper(e);
        lawer |= islower(e);
        unique &= used.find(e) == used.end();
        used.emplace(e);
    }
    cout << Yes(upper && lawer && unique) << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
