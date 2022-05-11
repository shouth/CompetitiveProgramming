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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& e : a) cin >> e;
    auto minitr = min_element(begin(a), end(a)), maxitr = max_element(begin(a), end(a));
    int imin = *minitr, imax = *maxitr;
    vector<pair<int, int>> ans;

    if (imin < 0 && imax > 0) {
        if (imin + imax > 0) {
            for (int i = 1; i <= n; i++) ans.emplace_back(maxitr - begin(a) + 1, i);
        } else {
            for (int i = 1; i <= n; i++) ans.emplace_back(minitr - begin(a) + 1, i);
        }
    }

    if (imin + imax > 0) {
        for (int i = 1; i + 1 <= n; i++) ans.emplace_back(i, i + 1);
    } else {
        for (int i = n; i - 1 >= 1; i--) ans.emplace_back(i, i - 1);
    }

    cout << ans.size() << endl;
    for (auto& e : ans) cout << e.first << " " << e.second << endl;
}
