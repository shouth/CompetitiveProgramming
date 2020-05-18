#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

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

constexpr i64 MOD = 1'000'000'007;
// constexpr i64 MOD = 998'244'353;
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

void solve() {
    i64 n;
    cin >> n;

    vector<p64> ab(n);
    map<p64, p64> cnt;
    i64 ans0 = 0;
    for (auto& [ a, b ] : ab) {
        cin >> a >> b;
        if (a == 0 && b == 0) {
            ans0++;
        } else if (a == 0) {
            cnt[{ 1, 0 }].first++;
        } else if (b == 0) {
            cnt[{ 1, 0 }].second++;
        } else {
            if (b < 0) a *= -1, b *= -1;
            i64 g = gcd(a, b);
            a /= g, b /= g;
            (a < 0 ? cnt[{ b, -a }].first : cnt[{ a, b }].second)++;
        }
    }

    m64 ans1 = 1;
    for (auto& [ ignore, v ] : cnt) {
        ans1 *= modpow(2, v.first) + modpow(2, v.second) - 1;
    }
    cout << ans1 - 1 + ans0 << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
