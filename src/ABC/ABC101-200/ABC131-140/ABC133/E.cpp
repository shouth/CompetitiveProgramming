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

    friend istream &operator>>(istream &is, const modint &a) {
        i64 t;
        is >> t;
        a = modint(t);
        return is;
    }
};

constexpr i64 MOD = 1e9 + 7;
using m64 = modint<MOD>;

template<typename T = m64>
struct combinatorics {
    vector<T> fac;

    combinatorics(i32 n): fac(n+1) {
        fac[0] = 1;
        for (i32 i = 1; i <= n; i++) fac[i] = fac[i-1] * i;
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

int main() {
    i32 n, k;
    cin >> n >> k;
    vector<vector<i32>> g(n);
    for (i32 i = 0; i < n-1; i++) {
        i32 a, b;
        cin >> a >> b, a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    queue<i32> q;
    q.push(0);
    vector<i32> dist(n, -1);
    dist[0] = 0;
    combinatorics<> c(k);
    m64 ans = c.p(k, g[0].size()+1);
    while (!q.empty()) {
        i32 t = q.front(); q.pop();
        for (auto& e : g[t]) {
            if (dist[e] != -1) continue;
            ans *= c.p(k-2, g[e].size()-1);
            dist[e] = dist[t] + 1;
            q.push(e);
        }
    }

    cout << ans << endl;
}
