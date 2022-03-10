#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

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

    auto S = vector(H, string());
    for (auto& e : S) cin >> e;

    auto dist = vector(H, vector(W, m64()));
    auto accx = dist;
    auto accy = dist;
    auto accxy = dist;
    dist[0][0] = 1;

    for (i64 y = 0; y < H; y++) {
        for (i64 x = 0; x < W; x++) {
            if (x + 1 < W && S[y][x + 1] == '.') {
                dist[y][x + 1] += dist[y][x] + accx[y][x];
                accx[y][x + 1] = dist[y][x] + accx[y][x];
            }
            if (y + 1 < H && S[y + 1][x] == '.') {
                dist[y + 1][x] += dist[y][x] + accy[y][x];
                accy[y + 1][x] = dist[y][x] + accy[y][x];
            }
            if (x + 1 < W && y + 1 < H && S[y + 1][x + 1] == '.') {
                dist[y + 1][x + 1] += dist[y][x] + accxy[y][x];
                accxy[y + 1][x + 1] = dist[y][x] + accxy[y][x];
            }
        }
    }

    cout << dist[H - 1][W - 1] << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}