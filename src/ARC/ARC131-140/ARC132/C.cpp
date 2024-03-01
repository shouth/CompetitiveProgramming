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
#define yes(x) ((x) ? "yes" : "no")
#define Yes(x) ((x) ? "Yes" : "No")

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

template<i64 M>
struct modint {
    i64 x;

    constexpr modint(const i64 y = 0) noexcept : x(y >= 0 ? y % M : (M - (-y) % M) % M) {}

    constexpr modint operator+() const noexcept { return x; }
    constexpr modint operator-() const noexcept { return -x; }
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

    template<class ...Args>
    constexpr decltype(auto) operator++(Args ...) noexcept {
        conditional_t<sizeof...(Args), modint, modint &> res = *this;
        *this += 1;
        return res;
    }

    template<class ...Args>
    constexpr decltype(auto) operator--(Args ...) noexcept {
        conditional_t<sizeof...(Args), modint, modint &> res = *this;
        *this -= 1;
        return res;
    }

    constexpr bool operator==(const modint &rhs) noexcept { return x == rhs.x; }
    constexpr bool operator!=(const modint &rhs) noexcept { return x != rhs.x; }

    friend ostream &operator<<(ostream &os, const modint &p) {
        return os << p.x;
    }

    friend istream &operator>>(istream &is, modint &a) {
        i64 t;
        is >> t;
        a = t;
        return is;
    }
};

using modint1000000007 = modint<1'000'000'007>;
using modint998244353 = modint<998'244'353>;
using m64 = modint998244353;
constexpr m64 operator"" _m(unsigned long long n) { return n; }

void solve() {
    i64 n, d;
    cin >> n >> d;

    auto dp = vector(n + 1, vector(1ll << (2 * d + 1), m64()));
    dp[0][(1 << (d + 1)) - 1] = 1;
    for (i64 i = 0; i < n; i++) {
        i64 a;
        cin >> a;
        for (i64 x = 0; x < 1ll << (2 * d); x++) {
            if (__builtin_popcountll(x) != d) continue;
            if (a == -1) {
                for (i64 j = 0; j < 2 * d + 1; j++) {
                    if ((x >> j) & 1) continue;
                    dp[i + 1][x | (1ll << j)] += dp[i][x << 1 | 1];
                }
            } else {
                dp[i + 1][x | (1ll << (a - i - 1 + d))] += dp[i][x << 1 | 1];
            }
        }
    }
    cout << dp[n][(1 << (d + 1)) - 1] << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
