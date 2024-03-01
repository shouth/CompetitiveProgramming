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

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

template<i64 M>
struct modint {
    i64 x;

    constexpr modint(const i64 y = 0) noexcept : x(y >= 0 ? y % M : (M - (-y) % M) % M) {}

    constexpr modint operator-() const noexcept { return modint(-x); }
    constexpr modint operator+(const modint &rhs) const noexcept { return modint(*this) += rhs; }
    constexpr modint operator-(const modint &rhs) const noexcept { return modint(*this) -= rhs; }
    constexpr modint operator*(const modint &rhs) const noexcept { return modint(*this) *= rhs; }
    constexpr modint operator/(const modint &rhs) const noexcept { return modint(*this) /= rhs; }

    constexpr modint &operator+=(const modint &rhs) noexcept {
        x += rhs.x;
        if (x >= M) x -= M;
        return *this;
    }

    constexpr modint &operator-=(const modint &rhs) noexcept {
        if (x < rhs.x) x += M;
        x -= rhs.x;
        return *this;
    }

    constexpr modint &operator*=(const modint &rhs) noexcept {
        x = x * rhs.x % M;
        return *this;
    }

    constexpr modint &operator/=(const modint &rhs) noexcept {
        i64 a = rhs.x, b = M, u = 1, v = 0;
        while (b > 0) {
            i64 t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        *this *= u;
        return *this;
    }

    friend ostream &operator<<(ostream &os, const modint &p) {
        return os << p.x;
    }

    friend istream &operator>>(istream &is, modint &a) {
        i64 t;
        is >> t;
        a = modint(t);
        return is;
    }
};

constexpr i64 MOD = 1 ? 1'000'000'007 : 998'244'353;
using m64 = modint<MOD>;
constexpr m64 operator"" _m(unsigned long long n) { return m64(n); }

template<typename T>
struct combinatorics {
    vector<T> fac_, ifac_;

    combinatorics(i64 n): fac_(n + 1), ifac_(n + 1) {
        fac_[0] = ifac_[n] = 1;
        for (i64 i = 0; i < n; i++) fac_[i + 1] = fac_[i] * (i + 1);
        ifac_[n] /= fac_[n];
        for (i64 i = n; i > 0; i--) ifac_[i - 1] = ifac_[i] * i;
    }

    T p(i64 n, i64 k) const {
        if (k < 0 || n < k) return 0;
        return fac_[n] * ifac_[n - k];
    }

    T c(i64 n, i64 k) const {
        if (k < 0 || n < k) return 0;
        return p(n, k) * ifac_[k];
    }

    T h(i64 n, i64 k) const {
        return c(n + k - 1, k);
    }
};

void solve() {
    i64 h, w, n;
    cin >> h >> w >> n;

    vector<p64> b(n);
    for (auto& [ r, c ] : b) cin >> r >> c;
    b.emplace_back(1, 1);
    b.emplace_back(h, w);
    sort(all(b));

    vector<m64> dp(n + 2);
    dp[0] = 1;
    combinatorics<m64> c(h + w);
    for (i64 i = 0; i < n + 2; i++) {
        for (i64 j = i + 1; j < n + 2; j++) {
            auto& [ xb, yb ] = b[i];
            auto& [ xe, ye ] = b[j];
            if (yb > ye) continue;
            dp[j] -= dp[i] * c.c(xe - xb + ye - yb, xe - xb);
        }
    }
    cout << -dp[n + 1] << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
