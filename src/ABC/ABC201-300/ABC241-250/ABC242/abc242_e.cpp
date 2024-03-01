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
using m64 = modint998244353;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 T;
    cin >> T;

    for (i64 _ = 0; _ < T; _++) {
        i64 N;
        cin >> N;
        string S;
        cin >> S;

        m64 ans = 0;
        for (i64 i = 0; i < (N + 1) / 2; i++) {
            ans = ans * 26 + S[i] - 'A';
        }
        if (!lexicographical_compare(begin(S) + (N + 1) / 2, begin(S) + N, rend(S) - N / 2, rend(S))) ans++;
        cout << ans.val() << "\n";
    }
    cout << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
