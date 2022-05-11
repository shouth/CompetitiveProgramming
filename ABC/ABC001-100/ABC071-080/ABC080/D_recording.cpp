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
    int n, c;
    cin >> n >> c;
    vector<vector<pair<int, int>>> st(c);
    for (int i = 0; i < n; i++) {
        int si, ti, ci;
        cin >> si >> ti >> ci;
        st[ci-1].emplace_back(si, ti);
    }

    vector<int> imos(1e5+10);
    for (auto& e : st) {
        sort(begin(e), end(e));
        for (int l = 0, r = 0; r < e.size(); r++) {
            if (r + 1 < e.size() && e[r].second == e[r+1].first) continue;
            imos[e[l].first-1]++, imos[e[r].second]--;
            l = r + 1;
        }
    }

    partial_sum(begin(imos), end(imos), begin(imos));
    cout << *max_element(begin(imos), end(imos)) << endl;
}
