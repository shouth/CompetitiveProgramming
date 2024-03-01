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

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    map<char, int> a, r;
    for (auto& e : s) a[e]++, r[e]++;
    string ans;
    int d = 0;
    for (auto& e : s) {
        int m = 0;
        for (char c = 'a'; c <= 'z'; c++) m += min(a[c], r[c]);
        for (char c = 'a'; c <= 'z'; c++) {
            if (r[c] == 0) continue;
            int nd = d + (e == c);
            int nm = m - min(a[c], r[c]) - min(a[e], r[e]) + min(a[c], r[c] - 1) + min(a[e] - 1, r[e]) + 2 * (c == e);
            if (n - nd - nm <= k) {
                ans += c, d = nd, a[e]--, r[c]--;
                break;
            }
        }
    }
    cout << ans << endl;
}
