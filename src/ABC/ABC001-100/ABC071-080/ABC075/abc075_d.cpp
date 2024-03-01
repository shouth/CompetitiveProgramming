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
    int64_t n, k;
    cin >> n >> k;
    vector<pair<int64_t, int64_t>> x(n), y(n), xy(n);
    for (int i = 0; i < n; i++) {
        x[i].second = y[i].second = i;
        cin >> x[i].first >> y[i].first;
        xy[i].first = x[i].first, xy[i].second = y[i].first;
    }
    sort(begin(x), end(x));
    sort(begin(y), end(y));

    int64_t ans = INT64_MAX;
    for (int xi = 0; xi+1 < n; xi++) {
        for (int xj = xi+1; xj < n; xj++) {
            for (int yi = 0; yi+1 < n; yi++) {
                for (int yj = yi+1; yj < n; yj++) {
                    int64_t left = x[xi].first, right = x[xj].first;
                    int64_t bottom = y[yi].first, top = y[yj].first;
                    vector<int64_t> use { x[xi].second, x[xj].second, y[yi].second, y[yj].second };
                    if (any_of(begin(use), end(use), [&](auto a) {
                        return xy[a].first < left || right < xy[a].first || xy[a].second < bottom || top < xy[a].second;
                    })) continue;

                    int c = 0;
                    for (int m = 0; m < n; m++) {
                        if (left <= xy[m].first && xy[m].first <= right && bottom <= xy[m].second && xy[m].second <= top) c++;
                    }
                    if (c >= k) ans = min(ans, (top - bottom) * (right - left));
                }
            }
        }
    }

    cout << ans << endl;
}
