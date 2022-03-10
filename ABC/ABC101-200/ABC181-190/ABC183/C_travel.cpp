#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 N, K;
    cin >> N >> K;

    auto T = vector(N, vector(N, i64()));
    for (auto& es : T) {
        for (auto& e : es) {
            cin >> e;
        }
    }

    auto path = vector(N + 1, i64(0));
    iota(begin(path) + 1, end(path) - 1, 1);

    i64 ans = 0;
    do {
        i64 sum = 0;
        for (i64 i = 0; i + 1 <= N; i++) sum += T[path[i]][path[i + 1]];
        if (sum == K) ans++;
    } while (next_permutation(begin(path) + 1, end(path) - 1));
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}