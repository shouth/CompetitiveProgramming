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
    i64 N, M, X, Y;
    cin >> N >> M >> X >> Y, X--, Y--;

    struct train { i64 to, time, interval; };

    vector<vector<train>> trains(N);
    for (i64 i = 0; i < M; i++) {
        i64 A, B, T, K;
        cin >> A >> B >> T >> K, A--, B--;
        trains[A].push_back({ B, T, K });
        trains[B].push_back({ A, T, K });
    }

    vector<i64> times(N, -1);
    priority_queue<p64, vector<p64>, greater<p64>> pq;
    pq.emplace(0, X);

    while (!pq.empty()) {
        auto [ timesum, cur ] = pq.top();
        pq.pop();

        if (times[cur] != -1) continue;
        times[cur] = timesum;

        for (auto &[ nxt, time, interval ] : trains[cur]) {
            if (times[nxt] != -1) continue;
            pq.emplace((timesum + interval - 1) / interval * interval + time, nxt);
        }
    }

    cout << times[Y] << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
