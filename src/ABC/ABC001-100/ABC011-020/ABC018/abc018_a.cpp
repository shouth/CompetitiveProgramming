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
    vector<pair<int, int>> abc(3);
    for (int i = 0; i < 3; i++) {
        int t;
        cin >> t;
        abc[i] = { t, i };
    }

    sort(begin(abc), end(abc), greater<>());
    vector<int> ans(3);
    for (int i = 0; i < 3; i++) ans[abc[i].second] = i+1;
    for (auto& e : ans) cout << e << endl;
}
