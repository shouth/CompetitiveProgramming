#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 n, q;
    cin >> n >> q;

    vector<multiset<i64, greater<>>> kindergarten(2e5), rates(2e5);
    multiset<i64> equality;
    vector<i64> belongs(n), rate(n);
    for (i64 i = 0; i < n; i++) {
        i64 a, b;
        cin >> a >> b, b--;
        rate[i] = a, belongs[i] = b;
        kindergarten[b].emplace(i);
        rates[b].emplace(a);
    }

    for (i64 i = 0; i < (i64) 2e5; i++) {
        if (!kindergarten[i].empty()) equality.emplace(*rates[i].begin());
    }

    for (i64 i = 0; i < q; i++) {
        i64 c, d;
        cin >> c >> d, c--, d--;

        equality.erase(equality.find(*rates[belongs[c]].begin()));
        rates[belongs[c]].erase(rates[belongs[c]].find(rate[c]));
        if (!rates[belongs[c]].empty()) equality.emplace(*rates[belongs[c]].begin());
        belongs[c] = d;
        if (!rates[d].empty()) equality.erase(equality.find(*rates[d].begin()));
        rates[d].insert(rate[c]);
        equality.emplace(*rates[d].begin());
        cout << *equality.begin() << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
