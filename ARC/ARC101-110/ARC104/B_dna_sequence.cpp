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
using u64 = uint_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 N;
    cin >> N;
    string S;
    cin >> S;

    vector<i64> A(N + 1), T(N + 1), C(N + 1), G(N + 1);
    for (i64 i = 0; i < N; i++) {
        switch (S[i]) {
        case 'A':
            A[i + 1] = 1;
            break;
        case 'T':
            T[i + 1] = 1;
            break;
        case 'C':
            C[i + 1] = 1;
            break;
        case 'G':
            G[i + 1] = 1;
            break;
        }
    }

    partial_sum(all(A), begin(A));
    partial_sum(all(T), begin(T));
    partial_sum(all(C), begin(C));
    partial_sum(all(G), begin(G));

    i64 ans = 0;
    for (i64 i = 0; i < N; i++) {
        for (i64 j = i + 1; j <= N; j++) {
            if (A[j] - A[i] == T[j] - T[i] && C[j] - C[i] == G[j] - G[i]) ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
