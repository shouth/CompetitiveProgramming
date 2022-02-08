#include<bits/stdc++.h>
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

void solve() {
    i64 H, W, X, Y;
    cin >> H >> W >> X >> Y, X--, Y--;
    vector<string> S(H);
    for (auto& e : S) cin >> e;

    if (S[X][Y] == '#') {
        cout << 0 << endl;
        return;
    }

    i64 ans = 1;
    for (i64 x = X - 1; x >= 0 && S[x][Y] == '.'; x--) ans++;
    for (i64 x = X + 1; x < H && S[x][Y] == '.'; x++) ans++;
    for (i64 y = Y - 1; y >= 0 && S[X][y] == '.'; y--) ans++;
    for (i64 y = Y + 1; y < W && S[X][y] == '.'; y++) ans++;
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
