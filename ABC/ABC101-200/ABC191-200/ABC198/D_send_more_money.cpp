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

void solve() {
    string S1, S2, S3;
    cin >> S1 >> S2 >> S3;
    string s = S1 + S2 + S3;
    sort(all(s));
    s.erase(unique(all(s)), s.end());

    auto m = vector<i64>(26, -1);
    auto u = vector<i64>(10, 0);
    auto dfs = [&](auto &rec, i64 depth) -> bool {
        if (depth == (i64) s.size()) {
            if (m[S1[0] - 'a'] == 0 || m[S2[0] - 'a'] == 0 || m[S3[0] - 'a'] == 0) return false;
            auto f = [&](const string &str) {
                i64 d = 1, res = 0;
                for (i64 i = str.size() - 1; i >= 0; i--) {
                    res += m[str[i] - 'a'] * d;
                    d *= 10;
                }
                return res;
            };
            i64 n1 = f(S1), n2 = f(S2), n3 = f(S3);
            if (n1 + n2 == n3) {
                cout << n1 << "\n" << n2 << "\n" << n3 << endl;
                return true;
            }
        } else {
            for (i64 i = 0; i < 10; i++) {
                if (!u[i]) {
                    u[i] = 1;
                    m[s[depth] - 'a'] = i;
                    if (rec(rec, depth + 1)) return true;
                    m[s[depth] - 'a'] = -1;
                    u[i] = 0;
                }
            }
        }
        return false;
    };
    if (s.size() > 10 || !dfs(dfs, 0)) {
        cout << "UNSOLVABLE" << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
