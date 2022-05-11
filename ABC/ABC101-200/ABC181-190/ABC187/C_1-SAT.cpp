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
#define rall(x) rbegin(x), rend(x)

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 N;
    cin >> N;

    set<string> good, bad;
    for (i64 i = 0; i < N; i++) {
        string S;
        cin >> S;
        if (S[0] != '!') {
            good.insert(S);
        } else {
            bad.insert(S.substr(1));
        }
    }

    for (auto &e : good) {
        if (bad.find(e) != bad.end()) {
            cout << e << endl;
            return;
        }
    }

    cout << "satisfiable" << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
