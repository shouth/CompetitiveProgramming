#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

struct edge {
    i64 A, B, C;
};

void solve() {
    i64 N, M, P;
    cin >> N >> M >> P;

    auto edges = vector<edge>(M);
    for (auto& [ A, B, C ] : edges) {
        cin >> A >> B >> C, A--, B--, C = -(C - P);
    }

    auto costs = vector<i64>(N, INF);
    costs[0] = 0;

    for (i64 i = 0; i < N; i++) {
        for (auto& [ A, B, C ] : edges) {
            if (costs[A] != INF && costs[A] + C < costs[B]) costs[B] = costs[A] + C;
        }
    }

    for (i64 i = 0; i < N; i++) {
        for (auto& [ A, B, C ] : edges) {
            if (costs[A] != INF && costs[A] + C < costs[B]) costs[B] = -INF;
        }
    }

    cout << (costs[N - 1] == -INF ? -1 : max(-costs[N - 1], 0l)) << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
