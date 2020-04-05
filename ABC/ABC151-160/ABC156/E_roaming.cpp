#include<bits/stdc++.h>
using namespace std;

using i32 = int_fast32_t;
using i64 = int_fast64_t;

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

constexpr i64 MOD = 1e9 + 7;
using m64 = modint<MOD>;

template<typename T>
struct combinatorics {
    vector<T> fac;

    combinatorics(i32 n): fac(2*n+1) {
        fac[0] = 1;
        for (i32 i = 1; i <= 2*n; i++) fac[i] = fac[i-1] * i;
    }

    T p(i32 n, i32 k) const {
        if (k < 0 || n < k) return 0;
        return fac[n] / fac[n-k];
    }

    T c(i32 n, i32 k) const {
        if (k < 0 || n < k) return 0;
        return fac[n] / (fac[k] * fac[n-k]);
    }

    T h(i32 n, i32 k) const {
        return c(n+k-1, k);
    }
};

using combi = combinatorics<m64>;

int main() {
    i32 n, k;
    cin >> n >> k;

    combi c(n);
    m64 ans = 0;
    for (i32 m = 0; m < min(n, k); m++) {
        ans += c.c(n, m) * c.h(n-m, m);
    }

    cout << ans << endl;
}
