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
#define yes(x) ((x) ? "yes" : "no")
#define Yes(x) ((x) ? "Yes" : "No")

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 N;
    cin >> N;

    vector<i64> a(1 << N);
    map<i64, vector<i64>> group;
    for (ssize_t i = 0; i < (1 << N); i++) {
        cin >> a[i];
        group[a[i]].push_back(i + 1);
    }

    for (ssize_t i = 0; i <= N; i++) {
        if ((i == 0 && group[1].size() != 1)
            || (i > 0 && group[1l << i].size() != (1l << (i - 1)))) {
            cout << -1 << endl;
            return;
        }
    }

    vector<i64> tournament(1 << N);
    for (ssize_t n = 0; n <= N; n++) {
        for (ssize_t i = 0; i < (1 << N); i += (1 << n)) {
            tournament[i] = 1 << (N - n);
        }
    }

    for (ssize_t i = 0; i < (1 << N); i++) {
        i64 rank = tournament[i];
        cout << (i == 0 ? "" : " ") << group[rank].back();
        group[rank].pop_back();
    }

    cout << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
