#include<bits/stdc++.h>
#include<atcoder/all>

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define yes(x) ((x) ? "yes" : "no")
#define Yes(x) ((x) ? "Yes" : "No")

using namespace std;
using namespace atcoder;

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;
using m64 = modint1000000007;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 N, M;
    cin >> N >> M;
    auto AB = vector<p64>(N);
    for (auto &[ A, _ ] : AB) cin >> A;
    for (auto &[ _, B ] : AB) cin >> B;
    auto CD = vector<p64>(M);
    for (auto &[ C, _ ] : CD) cin >> C;
    for (auto &[ _, D ] : CD) cin >> D;

    sort(all(AB), greater());
    sort(all(CD), greater());

    auto hs = multiset<i64>();
    for (ssize_t i = 0, j = 0; i < N; i++) {
        auto [ A, B ] = AB[i];
        for (; j < M; j++) {
            auto [ C, D ] = CD[j];
            if (A > C) break;
            hs.emplace(D);
        }
        auto itr = hs.lower_bound(B);
        if (itr == hs.end()) {
            cout << "No" << endl;
            return;
        }
        hs.erase(itr);
    }
    cout << "Yes" << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
