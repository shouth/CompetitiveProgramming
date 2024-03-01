#include <utility>
#include <bitset>
#include <tuple>
#include <string>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <complex>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

constexpr int MOD = 1e9 + 7;

vector<int> pos(26, -1), unused, dp;
int n = 0;

bool check(int grid, int place) {
    if ((grid >> place) & 1) return false;
    if (place / 5 != 0 && place / 5 != 4
        && ((grid >> (place - 5)) & 1) != ((grid >> (place + 5)) & 1)) return false;
    if (place % 5 != 0 && place % 5 != 4
        && ((grid >> (place - 1)) & 1) != ((grid >> (place + 1)) & 1)) return false;
    return true;
}

int dfs(int grid, int manager, int num) {
    if (pos[num] != -1) {
        int ngrid = grid - (1 << pos[num]);
        return check(ngrid, pos[num]) ? dfs(ngrid, manager, num - 1) : 0;
    }

    if (dp[manager] != -1) {
        return dp[manager];
    }

    dp[manager] = 0;
    for (int i = 0; i < n; i++) {
        int ngrid = grid - (1 << unused[i]);
        if (check(ngrid, unused[i])) {
            dp[manager] += dfs(ngrid, manager - (1 << i), num - 1);
            dp[manager] %= MOD;
        }
    }

    return dp[manager];
}

int main() {
    for (int i = 0; i < 25; i++) {
        int x;
        cin >> x;
        if (x) {
            pos[x] = i;
        } else {
            n++;
            unused.push_back(i);
        }
    }
    dp.resize(1 << n, -1);
    dp[0] = 1;
    cout << dfs((1 << 25) - 1, (1 << n) - 1, 25) << endl;
}
