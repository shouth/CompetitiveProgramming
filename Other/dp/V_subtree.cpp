#include <utility>
#include <bitset>
#include <tuple>
#include <string>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <complex>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

struct dynamic_modint {
    i64 x;

    static i64 &mod() {
        static i64 mod = 0;
        return mod;
    }

    dynamic_modint(const i64 y = 0) noexcept : x(y >= 0 ? y % mod() : (mod() - (-y) % mod()) % mod()) {}

    dynamic_modint operator-() const noexcept { return dynamic_modint(-x); }
    dynamic_modint operator+(const dynamic_modint &rhs) const noexcept { return dynamic_modint(*this) += rhs; }
    dynamic_modint operator-(const dynamic_modint &rhs) const noexcept { return dynamic_modint(*this) -= rhs; }
    dynamic_modint operator*(const dynamic_modint &rhs) const noexcept { return dynamic_modint(*this) *= rhs; }
    dynamic_modint operator/(const dynamic_modint &rhs) const noexcept { return dynamic_modint(*this) /= rhs; }

    dynamic_modint &operator+=(const dynamic_modint &rhs) noexcept {
        x += rhs.x;
        if (x >= mod()) x -= mod();
        return *this;
    }

    dynamic_modint &operator-=(const dynamic_modint &rhs) noexcept {
        if (x < rhs.x) x += mod();
        x -= rhs.x;
        return *this;
    }

    dynamic_modint &operator*=(const dynamic_modint &rhs) noexcept {
        x = x * rhs.x % mod();
        return *this;
    }

    dynamic_modint &operator/=(const dynamic_modint &rhs) noexcept {
        i64 a = rhs.x, b = mod(), u = 1, v = 0;
        while (b > 0) {
            i64 t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        *this *= u;
        return *this;
    }

    friend ostream &operator<<(ostream &os, const dynamic_modint &p) {
        return os << p.x;
    }

    friend istream &operator>>(istream &is, dynamic_modint &a) {
        i64 t;
        is >> t;
        a = dynamic_modint(t);
        return is;
    }
};

using d64 = dynamic_modint;
d64 operator"" _d(unsigned long long x) { return d64(x); }

void solve() {
    i64 n, m;
    cin >> n >> m;
    vector<vector<i64>> t(n);
    for (i64 i = 0; i < n - 1; i++) {
        i64 x, y;
        cin >> x >> y, x--, y--;
        t[x].emplace_back(y);
        t[y].emplace_back(x);
    }

    d64::mod() = m;
    vector<d64> dp(n, 1);
    {
        auto f = [&](auto g, i64 cur, i64 from) -> d64 {
            for (auto& e : t[cur]) {
                if (e != from) dp[cur] *= g(g, e, cur) + 1;
            }
            return dp[cur];
        };
        f(f, 0, -1);
    }
    {
        auto f = [&](auto g, i64 cur, i64 from, d64 pval) -> void {
            i64 d = t[cur].size();
            vector<d64> l(d), r(d);
            for (i64 i = 0; i < d; i++) {
                if (t[cur][i] == from) {
                    l[i] = r[i] = pval + 1;
                    dp[cur] *= pval + 1;
                } else {
                    l[i] = r[i] = dp[t[cur][i]] + 1;
                }
            }
            for (i64 i = 0; i + 1 < d; i++) l[i + 1] *= l[i];
            for (i64 i = d - 1; i > 0; i--) r[i - 1] *= r[i];

            for (i64 i = 0; i < d; i++) {
                if (t[cur][i] == from) continue;

                d64 val = 1;
                if (i != 0) val *= l[i - 1];
                if (i != d - 1) val *= r[i + 1];

                g(g, t[cur][i], cur, val);
            }
        };
        f(f, 0, -1, 0);
    }

    for (auto& e : dp) cout << e << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
