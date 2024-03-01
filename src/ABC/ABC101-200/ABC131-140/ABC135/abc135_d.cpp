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

constexpr int64_t MOD = 1e9 + 7;

int main() {
    string s;
    cin >> s;
    reverse(begin(s), end(s));

    vector<vector<int>> surplus(s.size(), vector<int>(13));
    if (s[0] == '?') {
        for (int i = 0; i < 10; i++) surplus[0][i]++;
    } else {
        surplus[0][s[0] - '0']++;
    }

    for (int i = 1, t = 10; i < s.size(); i++, t = t * 10 % 13) {
        for (int n = 0; n < 13; n++) {
            if (s[i] == '?') {
                for (int m = 0; m < 10; m++) {
                    surplus[i][(n + m * t) % 13] += surplus[i-1][n];
                    surplus[i][(n + m * t) % 13] %= MOD;
                }
            } else {
                surplus[i][(n + (s[i] - '0') * t) % 13] += surplus[i-1][n];
                surplus[i][(n + (s[i] - '0') * t) % 13] %= MOD;
            }
        }
    }

    cout << surplus[s.size() - 1][5] << endl;
}
