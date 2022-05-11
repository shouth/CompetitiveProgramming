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

constexpr int64_t MOD = 1e9 + 7;

int main() {
    int64_t n;
    cin >> n;

    vector<vector<int64_t>> dp(61, vector<int64_t>(3));
    dp[60][0] = 1;
    for (int i = 60; i-1 >= 0; i--) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                int s = min(2l, 2*j + (n >> (i-1) & 1) - k);
                if (s >= 0) dp[i-1][s] = (dp[i-1][s] + dp[i][j]) % MOD;
            }
        }
    }

    cout << (dp[0][0] + dp[0][1] + dp[0][2]) % MOD << endl;
}
