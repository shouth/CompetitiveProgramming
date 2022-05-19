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

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define yes(x) ((x) ? "yes" : "no")
#define Yes(x) ((x) ? "Yes" : "No")

using namespace std;
using namespace atcoder;

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;
using m64 = modint1000000007;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 N;
    cin >> N;
    auto S = vector<string>(N);
    for (auto &e : S) cin >> e;

    auto cords = vector(14, vector(6, p64()));
    for (i64 i = 0; i < 6; i++) {
        cords[0][i] = { i, i };
        cords[1][i] = { i, 5 - i };

        for (i64 j = 0; j < 6; j++) {
            cords[2 + i][j] = { i, j };
            cords[8 + i][j] = { j, i };
        }
    }

    for (i64 i = 0; i + 6 <= N; i++) {
        for (i64 j = 0; j + 6 <= N; j++) {
            for (auto &line : cords) {
                i64 cnt = count_if(all(line), [&](p64 cord) {
                    auto [ di, dj ] = cord;
                    return S[i + di][j + dj] == '.';
                });
                if (cnt <= 2) {
                    cout << "Yes" << endl;
                    return;
                }
            }
        }
    }
    cout << "No" << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
