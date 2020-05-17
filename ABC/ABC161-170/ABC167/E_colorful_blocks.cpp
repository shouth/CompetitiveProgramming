#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using f64 = double;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

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

constexpr i64 MOD = 998244353;
using m64 = modint<MOD>;

m64 modpow(m64 x, i64 n) {
    m64 res = 1;
    while (n > 0) {
        if (n & 1) res *= x;
        x *= x;
        n >>= 1;
    }
    return res;
}

template<typename T = m64>
struct combinatorics {
    vector<T> fac;

    combinatorics(i64 n): fac(2*n+1) {
        fac[0] = 1;
        for (i64 i = 1; i <= 2*n; i++) fac[i] = fac[i-1] * i;
    }

    T p(i64 n, i64 k) const {
        if (k < 0 || n < k) return 0;
        return fac[n] / fac[n-k];
    }

    T c(i64 n, i64 k) const {
        if (k < 0 || n < k) return 0;
        return fac[n] / (fac[k] * fac[n-k]);
    }

    T h(i64 n, i64 k) const {
        return c(n+k-1, k);
    }
};

void solve() {
    i64 n, m, k;
    cin >> n >> m >> k;

    combinatorics c(n - 1);
    m64 ans = 0;
    for (i64 i = 0; i <= k; i++) {
        ans += c.c(n - 1, i) * modpow(m - 1, n - 1 - i) * m;
    }

    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
