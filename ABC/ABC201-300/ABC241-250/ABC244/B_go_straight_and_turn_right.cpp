#include<bits/stdc++.h>
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
    i64 N;
    cin >> N;
    string T;
    cin >> T;

    i64 x = 0, y = 0, r = 'e';
    for (auto &t : T) {
        if (t == 'S') {
            switch (r) {
            case 'e':
                x++;
                break;
            case 'w':
                x--;
                break;
            case 'n':
                y++;
                break;
            case 's':
                y--;
                break;
            }
        } else {
            switch (r) {
            case 'e':
                r = 's';
                break;
            case 's':
                r = 'w';
                break;
            case 'w':
                r = 'n';
                break;
            case 'n':
                r = 'e';
                break;
            }
        }
    }
    cout << x << " " << y << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
