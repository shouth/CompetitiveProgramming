#include<bits/stdc++.h>
using namespace std;

int r, g, b, m;
vector<vector<int>> dp;

int cost(int p, int q) {
    return abs(p - (r + g < q ? 1100 : r < q ? 1000 : 900));
}

int dfs(int p, int q) {
    return dp[p][q] != -1 ? dp[p][q] : dp[p][q] = min(dfs(p-1, q), cost(p, q) + dfs(p-1, q-1));
}

int main() {
    cin >> r >> g >> b, m = r + g + b;
    dp.assign(2001, vector<int>(m+1, -1));
    for (auto& e : dp[0]) e = INT_MAX / 2;
    for (auto& e : dp) e[0] = 0;
    cout << dfs(2000, m) << endl;
}
