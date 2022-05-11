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

vector<pair<int, int>> xy;
map<vector<int>, int> dp;

int dfs(int x1, int y1, int x2, int y2) {
    if (x1 > x2 || y1 > y2) swap(x1, x2), swap(y1, y2);
    if (dp[{x1, y1, x2, y2}] != 0) return dp[{x1, y1, x2, y2}];
    int res = 0;
    for (auto& e : xy) {
        int xe, ye;
        tie(xe, ye) = e;
        if (xe < x1 || x2 < xe || ye < y1 || y2 < ye) continue;
        int can = (x2 - x1 + 1) + (y2 - y1 + 1) - 1;
        if (xe != x2 && ye != y2) can += dfs(xe+1, ye+1,   x2,   y2);
        if (x1 != xe && y1 != ye) can += dfs(  x1,   y1, xe-1, ye-1);
        if (x1 != xe && ye != y2) can += dfs(  x1, ye+1, xe-1,   y2);
        if (xe != x2 && y1 != ye) can += dfs(xe+1,   y1,   x2, ye-1);
        res = max(res, can);
    }
    return dp[{x1, y1, x2, y2}] = res;
}

int main() {
    int w, h;
    cin >> w >> h;
    int n;
    cin >> n;

    xy.resize(n);
    for (auto& e : xy) cin >> e.first >> e.second;
    cout << dfs(1, 1, w, h) << endl;
}
