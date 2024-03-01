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
    vector<vector<char>> s(h+2, vector<char>(w+2, '.'));
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> s[i][j];
        }
    }

    vector<int> dxy { 0, -1, 1, 1, 0, 1, -1, -1, 0 };
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (s[i][j] == '#') {
                cout << '#';
            } else {
                char b = '0';
                for (int d = 0; d < 8; d++) {
                    if (s[i+dxy[d]][j+dxy[d+1]] == '#') b++;
                }
                cout << b;
            }
        }
        cout << endl;
    }
}
