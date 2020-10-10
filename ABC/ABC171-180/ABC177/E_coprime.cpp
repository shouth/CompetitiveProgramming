#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

struct factorization {
    vector<i64> spf;

    factorization(i64 n): spf(n + 1) {
        iota(all(spf), 0);
        for (i64 i = 2; i <= n; i++) {
            if (spf[i] != i) continue;
            for (i64 j = i + i; j <= n; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }

    map<i64, i64> operator()(i64 n) {
        map<i64, i64> res;
        while (n > 1) {
            res[spf[n]]++;
            n /= spf[n];
        }
        return res;
    }
};

void solve() {
    i64 N;
    cin >> N;
    vector<i64> A(N);
    for (auto& e : A) cin >> e;

    set<i64> cnt;
    factorization f(1e6);
    bool flag = true;
    for (auto& e : A) {
        for (auto& [ k, v ] : f(e)) {
            if (cnt.find(k) != cnt.end()) {
                flag = false;
                break;
            } else {
                cnt.emplace(k);
            }
        }
    }

    if (flag) {
        cout << "pairwise coprime" << endl;
        return;
    }

    i64 g = reduce(all(A), 0, gcd<i64, i64>);
    if (g == 1) {
        cout << "setwise coprime" << endl;
        return;
    }

    cout << "not coprime" << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
