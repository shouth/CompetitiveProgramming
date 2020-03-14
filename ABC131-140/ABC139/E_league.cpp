#include<bits/stdc++.h>
using namespace std;

using i32 = int_fast32_t;
using i64 = int_fast64_t;
using p32 = pair<i32, i32>;

vector<vector<i32>> g;
vector<i32> visited, dp;

i32 dfs(i32 n = 0) {
    if (visited[n] == 2) return dp[n];
    visited[n] = 1;
    for (auto& e : g[n]) {
        if (visited[e] == 1) return -1;

        i32 tmp = dfs(e);
        if (tmp == -1) return -1;
        dp[n] = max(tmp + 1, dp[n]);
    }
    visited[n] = 2;
    return dp[n];
}

i32 id(i32 a, i32 b) {
    return a < b ? id(b, a) : a * (a-1) / 2 + b + 1;
}

int main() {
    i32 n;
    cin >> n;

    g.resize(n * (n-1) / 2 + 1);
    for (i32 i = 0; i < n; i++) {
        i32 a = 0;
        for (i32 j = 0; j < n-1; j++) {
            i32 b;
            cin >> b, b = id(i, b-1);
            g[a].push_back(b);
            a = b;
        }
    }

    visited.resize(n * (n-1) / 2 + 1);
    dp.resize(n * (n-1) / 2 + 1);
    cout << dfs() << endl;
}
