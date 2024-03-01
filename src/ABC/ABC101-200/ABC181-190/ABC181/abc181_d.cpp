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
    string s;
    cin >> s;

    if (s.size() <= 3) {
        sort(all(s));
        do {
            i64 x = stoi(s);
            if (x % 8 == 0) {
                cout << "Yes" << endl;
                return;
            }
        } while (next_permutation(all(s)));
        cout << "No" << endl;
        return;
    }

    map<char, i64> cnt;
    for (auto& e : s) cnt[e]++;

    for (i64 x = 1000; x < 2000; x += 8) {
        string str = to_string(x);
        map<char, i64> tmp;
        for (i64 i = 1; i < 4; i++) tmp[str[i]]++;

        bool flag = true;
        for (auto& [ k, v ] : tmp) {
            if (cnt[k] < v) flag = false;
        }

        if (flag) {
            cout << "Yes" << endl;
            return;
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
