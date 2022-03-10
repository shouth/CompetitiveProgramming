#include<bits/stdc++.h>
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
    i64 M = 1 << (N - 1);
    i64 fa = 0, sa = 0, fidx, sidx;
    for (i64 i = 0; i < M; i++) {
        i64 A;
        cin >> A;
        if (fa < A) {
            fidx = i + 1;
            fa = A;
        }
    }
    for (i64 i = 0; i < M; i++) {
        i64 A;
        cin >> A;
        if (sa < A) {
            sidx = M + i + 1;
            sa = A;
        }
    }
    cout << (fa > sa ? sidx : fidx) << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
