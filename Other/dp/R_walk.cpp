#include<bits/stdc++.h>
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

void solve() {
    i64 n, k;
    cin >> n >> k;

    vector<vector<m64>> a(n, vector<m64>(n));
    for (auto& e : a) for (auto& f : e) cin >> f;

    vector<vector<m64>> sum(n, vector<m64>(n));
    for (i64 i = 0; i < n; i++) sum[i][i] = 1;
    for (; k > 0; k >>= 1) {
        if (k & 1) {
            vector<vector<m64>> tmp1(n, vector<m64>(n));
            for (i64 x = 0; x < n; x++) {
                for (i64 y = 0; y < n; y++) {
                    for (i64 z = 0; z < n; z++) {
                        tmp1[x][y] += sum[x][z] * a[z][y];
                    }
                }
            }
            sum = move(tmp1);
        }

        vector<vector<m64>> tmp2(n, vector<m64>(n));
        for (i64 x = 0; x < n; x++) {
            for (i64 y = 0; y < n; y++) {
                for (i64 z = 0; z < n; z++) {
                    tmp2[x][y] += a[x][z] * a[z][y];
                }
            }
        }
        a = move(tmp2);
    }

    m64 ans = 0;
    for (i64 i = 0; i < n; i++) {
        for (i64 j = 0; j < n; j++) {
            ans += sum[i][j];
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
