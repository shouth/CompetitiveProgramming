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
    int64_t r, c, k;
    cin >> r >> c >> k;
    int64_t n;
    cin >> n;
    vector<vector<int64_t>> rcs(r);
    vector<int64_t> ccn(c), sccn(c);

    for (int64_t i = 0; i < n; i++) {
        int64_t ri, ci;
        cin >> ri >> ci, ri--, ci--;
        rcs[ri].push_back(ci);
        ccn[ci]++, sccn[ci]++;
    }

    sort(begin(sccn), end(sccn));

    int64_t ans = 0;
    for (auto& e : rcs) {
        int64_t s = k - e.size();
        auto er = equal_range(begin(sccn), end(sccn), s);
        ans += distance(er.first, er.second);
        for (auto& f : e) {
            if (ccn[f] == s) ans--;
            if (ccn[f] == s + 1) ans++;
        }
    }
    cout << ans << endl;
}
