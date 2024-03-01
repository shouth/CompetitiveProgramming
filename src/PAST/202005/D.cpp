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

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 n;
    cin >> n;
    vector<string> ss(5);
    for (auto& e : ss) cin >> e;

    vector<vector<string>> nums {
        {
            "###",
            "#.#",
            "#.#",
            "#.#",
            "###",
        },
        {
            ".#.",
            "##.",
            ".#.",
            ".#.",
            "###",
        },
        {
            "###",
            "..#",
            "###",
            "#..",
            "###",
        },
        {
            "###",
            "..#",
            "###",
            "..#",
            "###",
        },
        {
            "#.#",
            "#.#",
            "###",
            "..#",
            "..#",
        },
        {
            "###",
            "#..",
            "###",
            "..#",
            "###",
        },
        {
            "###",
            "#..",
            "###",
            "#.#",
            "###",
        },
        {
            "###",
            "..#",
            "..#",
            "..#",
            "..#",
        },
        {
            "###",
            "#.#",
            "###",
            "#.#",
            "###",
        },
        {
            "###",
            "#.#",
            "###",
            "..#",
            "###",
        }
    };
    for (i64 i = 0; i < n; i++) {
        vector<string> num(5);
        for (i64 j = 0; j < 5; j++) num[j] = ss[j].substr(4 * i + 1, 3);

        for (i64 j = 0; j < 10; j++) {
            if (num == nums[j]) {
                cout << j;
                break;
            }
        }
    }
    cout << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
