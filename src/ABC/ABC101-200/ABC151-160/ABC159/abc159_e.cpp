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
using p32 = pair<i32, i32>;

vector<vector<i32>> dp;
vector<vector<i32>> choco;
i32 h, w, k;

i32 white(i32 h1, i32 w1, i32 h2, i32 w2) {
    return choco[h2][w2] - choco[h2][w1] - choco[h1][w2] + choco[h1][w1];
}

// (h1, h2]
i32 divide(const vector<i32> &hs) {
    i32 res = 0;
    for (i32 l = 0, r = 1; r+1 <= w; r++) {
        bool pack = false;
        for (i32 i = 0; i+1 < hs.size(); i++) {
            if (white(hs[i], l, hs[i+1], r+1) > k) {
                if (l == r) return INT32_MAX;
                pack = true;
            }
        }

        if (pack) {
            l = r;
            res++;
        }
    }

    for (i32 i = 0; i+1 < hs.size(); i++) {
        if (white(hs[i], w-1, hs[i+1], w) > k) {
            return INT32_MAX;
        }
    }

    return res;
}

int main() {
    cin >> h >> w >> k;
    choco.assign(h+1, vector<i32>(w+1));
    for (i32 i = 1; i <= h; i++) {
        for (i32 j = 1; j <= w; j++) {
            char c;
            cin >> c;
            choco[i][j] = c - '0';
        }
    }
    for (i32 i = 0; i <= h; i++) {
        for (i32 j = 0; j+1 <= w; j++) {
            choco[i][j+1] += choco[i][j];
        }
    }
    for (i32 i = 0; i+1 <= h; i++) {
        for (i32 j = 0; j <= w; j++) {
            choco[i+1][j] += choco[i][j];
        }
    }

    dp.assign(h+1, vector<i32>(h+1, -1));
    i32 ans = INT32_MAX;
    for (i32 i = 1 << (h-1); i < (1 << h); i++) {
        vector<i32> v {0};
        for (i32 j = 0; j < h; j++) {
            if ((i >> j) & 1) v.push_back(j + 1);
        }

        ans = min(ans, divide(v) + (i32) v.size()-2);
    }

    cout << ans << endl;
}
