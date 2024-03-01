#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Weverything"

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
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;
using m64 = modint1000000007;

constexpr i64 INF = numeric_limits<i64>::max() / 2;

#pragma clang diagnostic pop

void solve()
{
    auto S = string();
    cin >> S;
    auto chokudai = "chokudai"s;
    auto dp = vector<m64>(size(chokudai) + 1);
    dp.front() = 1;
    for (auto &c : S) {
        for (i64 i = 0; i < size(chokudai); ++i) {
            if (c == chokudai[i]) {
                dp[i + 1] += dp[i];
            }
        }
    }
    cout << dp.back().val() << endl;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
