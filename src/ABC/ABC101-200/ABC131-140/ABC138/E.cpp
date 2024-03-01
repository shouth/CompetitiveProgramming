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
    string s, t;
    cin >> s >> t;
    int64_t n = s.size();

    string ss = s + s;
    vector<vector<int>> next((int) 2 * n + 1, vector<int>(26, -1));
    for (int i = 2 * n - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) next[i][j] = next[i+1][j];
        next[i][ss[i] - 'a'] = i;
    }

    int64_t index = 0, loop = 0;
    for (auto e : t) {
        if (next[index][e - 'a'] == -1) {
            cout << -1 << endl;
            return 0;
        }

        if (next[index][e - 'a'] >= n) {
            loop++;
            index = next[index][e - 'a'] % n + 1;
        } else {
            index = next[index][e - 'a'] + 1;
        }
    }

    cout << index + loop * n << endl;
}
