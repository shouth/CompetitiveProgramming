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

constexpr i64 MOD = 1 ? 1'000'000'007 : 998'244'353;
using m64 = modint<MOD>;
constexpr m64 operator"" _m(unsigned long long n) { return m64(n); }

template<typename T>
T fastpow(T x, i64 n) {
    T res = 1;
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
    vector<i64> a(n);
    for (auto& e : a) cin >> e;

    if (a[0] != 0 || count(all(a), 0) != 1) {
        cout << 0 << endl;
        return;
    }

    sort(all(a));
    if (adjacent_find(all(a), [](i64 x, i64 y) { return y - x > 1; }) != end(a)) {
        cout << 0 << endl;
        return;
    }

    i64 precnt = 0, curcnt = 1;
    m64 ans = 1;
    for (i64 i = 0; i + 1 < n; i++) {
        if (a[i] != a[i + 1]) precnt = curcnt, curcnt = 0;
        curcnt++;
        ans *= fastpow(2_m, precnt) - 1;
        ans *= fastpow(2_m, curcnt - 1);
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
