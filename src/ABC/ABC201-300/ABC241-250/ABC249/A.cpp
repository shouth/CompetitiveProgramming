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

#include<atcoder/all>

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
    i64 A, B, C, D, E, F, X;
    cin >> A >> B >> C >> D >> E >> F >> X;

    auto f = [&](i64 a, i64 b, i64 c) -> i64 {
        i64 t = 0;
        i64 res = 0;
        while (true) {
            if (t + a <= X) {
                t += a;
                res += a * b;
            } else {
                res += (X - t) * b;
                return res;
            }
            if (t + c <= X) {
                t += c;
            } else {
                return res;
            }
        }
    };
    i64 takahashi = f(A, B, C);
    i64 aoki = f(D, E, F);
    if (takahashi > aoki) {
        cout << "Takahashi" << endl;
    } else if (takahashi < aoki) {
        cout << "Aoki" << endl;
    } else {
        cout << "Draw" << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
