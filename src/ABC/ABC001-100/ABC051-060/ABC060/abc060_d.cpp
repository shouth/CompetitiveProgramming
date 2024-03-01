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
    int64_t n, w;
    cin >> n >> w;
    int64_t base, tmp;
    cin >> base >> tmp;
    map<int64_t, vector<int64_t>> wv;
    for (int64_t i = base; i <= base+3; i++) wv[i].push_back(0);
    wv[base].push_back(tmp);
    for (int64_t i = 1; i < n; i++) {
        int64_t ww, vv;
        cin >> ww >> vv;
        wv[ww].push_back(vv);
    }

    for (int64_t i = base; i <= base+3; i++) {
        sort(begin(wv[i])+1, end(wv[i]), greater<>());
        partial_sum(begin(wv[i]), end(wv[i]), begin(wv[i]));
    }

    int64_t ans = 0;
    for (size_t i = 0; i < wv[base].size(); i++) {
        for (size_t j = 0; j < wv[base+1].size(); j++) {
            for (size_t k = 0; k < wv[base+2].size(); k++) {
                for (size_t l = 0; l < wv[base+3].size(); l++) {
                    if (i*base+j*(base+1)+k*(base+2)+l*(base+3) <= w) ans = max(ans, wv[base][i]+wv[base+1][j]+wv[base+2][k]+wv[base+3][l]);
                }
            }
        }
    }

    cout << ans << endl;
}
