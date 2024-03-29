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

int h, n;
vector<pair<int, int>> ab;
vector<int> dp;

int solve(int remain) {
    if (remain <= 0) return 0;
    if (dp[remain] != -1) return dp[remain];
    int res = INT_MAX;
    for (auto& e : ab) res = min(res, solve(remain - e.first) + e.second);
    return dp[remain] = res;
}

int main() {
    cin >> h >> n;
    ab.resize(n);
    dp.resize(h+1, -1);
    for (auto& e : ab) cin >> e.first >> e.second;
    cout << solve(h) << endl;
}
