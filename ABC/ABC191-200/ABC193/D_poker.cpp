#include<bits/stdc++.h>
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

i64 score(string str) {
    vector<i64> cnt(10);
    for (auto& e : str) cnt[e - '0']++;
    i64 res = 0;
    for (i64 i = 1; i < 10; i++) res += i * (i64) pow(10, cnt[i]);
    return res;
}

void solve() {
    i64 K;
    cin >> K;
    string S, T;
    cin >> S >> T;
    S.pop_back();
    T.pop_back();

    vector<i64> remain(10, K);
    for (auto& e : S) remain[e - '0']--;
    for (auto& e : T) remain[e - '0']--;
    i64 sum = accumulate(begin(remain) + 1, end(remain), 0);
    i64 patterns = sum * (sum - 1);

    i64 win = 0;
    for (i64 i = 1; i < 10; i++) {
        for (i64 j = 1; j < 10; j++) {
            i64 s = score(S + to_string(i));
            i64 t = score(T + to_string(j));
            if (s <= t) continue;

            if (i != j) {
                if (remain[i] > 0 && remain[j] > 0) win += remain[i] * remain[j];
            } else {
                if (remain[i] > 1) win += remain[i] * (remain[i] - 1);
            }
        }
    }

    cout << (double) win / (double) patterns << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
