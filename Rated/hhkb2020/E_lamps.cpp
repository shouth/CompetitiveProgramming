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
    i64 H, W;
    cin >> H >> W;

    auto S = vector<string>(H);
    for (auto& e : S) cin >> e;

    i64 allcnt = 0;
    for (auto& e : S) allcnt += count(all(e), '.');
    auto hcnt = vector(H, vector(W, -1l));
    auto wcnt = vector(H, vector(W, -1l));
    for (i64 i = 0; i < W; i++) {
        if (S[0][i] == '.') hcnt[0][i] = 1;
        for (i64 j = 1; j < H; j++) {
            if (S[j][i] == '#') continue;
            hcnt[j][i] = S[j - 1][i] == '#' ? 1 : hcnt[j - 1][i] + 1;
        }
        for (i64 j = H - 2; j >= 0; j--) {
            if (hcnt[j][i] == -1 || hcnt[j + 1][i] == -1) continue;
            hcnt[j][i] = hcnt[j + 1][i];
        }
    }
    for (i64 i = 0; i < H; i++) {
        if (S[i][0] == '.') wcnt[i][0] = 1;
        for (i64 j = 1; j < W; j++) {
            if (S[i][j] == '#') continue;
            wcnt[i][j] = S[i][j - 1] == '#' ? 1 : wcnt[i][j - 1] + 1;
        }
        for (i64 j = W - 2; j >= 0; j--) {
            if (wcnt[i][j] == -1 || wcnt[i][j + 1] == -1) continue;
            wcnt[i][j] = wcnt[i][j + 1];
        }
    }

    vector<m64> pow2(H * W + 1);
    pow2[0] = 1;
    for (i64 i = 0; i < H * W; i++) pow2[i + 1] = pow2[i] * 2;

    m64 ans = 0;
    for (i64 i = 0; i < H; i++) {
        for (i64 j = 0; j < W; j++) {
            if (S[i][j] == '#') continue;
            i64 spotcnt = hcnt[i][j] + wcnt[i][j] - 1;
            ans += (pow2[spotcnt] - 1) * pow2[allcnt - spotcnt];
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
