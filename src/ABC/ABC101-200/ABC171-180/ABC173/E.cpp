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

void solve() {
    i64 n, k;
    cin >> n >> k;

    if (k == n) {
        m64 ans = 1;
        for (i64 i = 0; i < n; i++) {
            i64 a;
            cin >> a;
            ans *= a;
        }
        cout << ans << endl;
        return;
    }

    deque<i64> pos, neg;
    for (i64 i = 0; i < n; i++) {
        i64 a;
        cin >> a;
        (a >= 0 ? pos : neg).emplace_back(a);
    }

    if (k % 2 == 1 && (i64) neg.size() == n) {
        m64 ans = 1;
        sort(all(neg), greater());
        for (i64 i = 0; i < k; i++) ans *= neg[i];
        cout << ans << endl;
        return;
    }

    sort(all(pos), greater());
    sort(all(neg));

    m64 ans = 1;
    while (k > 0) {
        if (pos.size() >= 2 && neg.size() >= 2) {
            if (k >= 2 && neg[0] * neg[1] >= pos[0] * pos[1]) {
                ans *= neg[0] * neg[1];
                neg.pop_front();
                neg.pop_front();
                k -= 2;
            } else {
                ans *= pos[0];
                pos.pop_front();
                k--;
            }
        } else if (k >= 2 && neg.size() >= 2) {
            ans *= neg[0] * neg[1];
            neg.pop_front();
            neg.pop_front();
            k -= 2;
        } else {
            ans *= pos[0];
            pos.pop_front();
            k--;
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
