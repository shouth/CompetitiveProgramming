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

using i32 = int_fast32_t;
using i64 = int_fast64_t;

int main() {
    vector<string> abc(3);
    for (auto& e : abc) cin >> e;
    sort(begin(abc), end(abc));
    i32 ans = INT32_MAX;
    do {
        string tmp;
        i32 n = abc[0].size();
        i32 m = abc[1].size();
        bool con = true;
        for (i32 i = 0; i < n; i++) {
            bool flag = true;
            for (i32 j = 0; i+j < n && j < m; j++) {
                if (abc[0][i+j] != '?' && abc[1][j] != '?' && abc[0][i+j] != abc[1][j]) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                con = false;
                tmp = i+m <= n ? abc[0] : abc[0].substr(0, i) + abc[1];
                break;
            }
        }

        if (con) {
            tmp = abc[0] + abc[1];
        }

        n = tmp.size();
        m = abc[2].size();
        con = true;
        for (i32 i = 0; i < n; i++) {
            bool flag = true;
            for (i32 j = 0; i+j < n && j < m; j++) {
                if (tmp[i+j] != '?' && abc[2][j] != '?' && tmp[i+j] != abc[2][j]) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                con = false;
                tmp = i+m <= n ? tmp : tmp.substr(0, i) + abc[2];
                break;
            }
        }

        if (con) {
            tmp += abc[2];
        }
        ans = min(ans, (i32) tmp.size());
    } while (next_permutation(begin(abc), end(abc)));
    cout << ans << endl;
}
