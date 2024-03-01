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
    int64_t n;
    cin >> n;
    vector<pair<int64_t, int64_t>> hs(n);
    for (auto& e : hs) cin >> e.first >> e.second;

    int64_t bottom = 0, top = 1e18;
    while (abs(top - bottom) > 1) {
        int64_t middle = (bottom + top) / 2;
        vector<int64_t> limit(n);
        for (int64_t i = 0; i < n; i++) {
            int64_t tmp = middle - hs[i].first;
            limit[i] = tmp < 0 ? -1 : tmp / hs[i].second;
        }
        sort(begin(limit), end(limit));
        bool f = true;
        for (int64_t i = 0; i < n; i++) {
            if (limit[i] < i) f = false;
        }
        (f ? top : bottom) = middle;
    }

    cout << top << endl;
}
