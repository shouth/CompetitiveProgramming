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
    int h, w;
    cin >> h >> w;
    vector<vector<char>> s(h+2, vector<char>(w+2));
    for (int i = 0; i < h + 2; i++) s[0][i] = s[h+1][i] = '.';
    for (int i = 0; i < h + 2; i++) s[i][0] = s[i][w+1] = '.';
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) cin >> s[i][j];
    }

    string ans = "Yes";
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (s[i][j] == '#' && s[i+1][j] == '.' && s[i][j+1] == '.' && s[i-1][j] == '.' && s[i][j-1] == '.') ans = "No";
        }
    }

    cout << ans << endl;
}
