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
    int64_t h, w, n;
    cin >> h >> w >> n;
    vector<int64_t> dxy { 0, 1, -1, -1, 0, 0, -1, 1, 1, 0 };
    map<pair<int64_t, int64_t>, int64_t> m;
    for (int i = 0; i < n; i++) {
        int64_t a, b;
        cin >> a >> b;
        for (int j = 0; j < 9; j++) {
            auto e = make_pair(a+dxy[j], b+dxy[j+1]);
            if ((1 < e.first && e.first < h) && (1 < e.second && e.second < w)) m[e]++;
        }
    }

    vector<int64_t> ans(10);
    for (auto& e : m) ans[e.second]++;
    ans[0] = (h-2) * (w-2) - accumulate(begin(ans)+1, end(ans), 0l);
    for (auto& e : ans) cout << e << endl;
}
