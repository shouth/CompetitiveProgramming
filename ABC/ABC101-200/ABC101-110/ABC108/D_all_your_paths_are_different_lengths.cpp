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
    int l;
    cin >> l;
    int n = log2(l);

    vector<tuple<int, int, int>> ans;
    for (int i = 0; i < n; i++) {
        ans.emplace_back(i + 1, i + 2, 0);
        ans.emplace_back(i + 1, i + 2, 1 << i);
    }

    for (int t = n; t >= 0; t--) {
        int s = l - (1 << t);
        if (s >= 1 << n) {
            ans.emplace_back(t + 1, n + 1, s);
            l = s;
        }
    }

    cout << n + 1 << " " << ans.size() << endl;
    for (auto& e : ans) cout << get<0>(e) << " " << get<1>(e) << " " << get<2>(e) << endl;
}
