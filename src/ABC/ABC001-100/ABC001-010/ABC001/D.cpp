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

int r(int t) {
    t = t / 5 * 5;
    if (t % 100 == 60) t = (t / 100 + 1) * 100;
    return t;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    for (auto& t : v) {
        int s, e;
        scanf("%04d-%04d", &s, &e);
        t = { r(s), r(e+4) };
    }
    v.push_back({ 10000, 10000 });

    sort(begin(v), end(v));
    pair<int, int> ans = v[0];
    for (auto& e : v) {
        if (e.first <= ans.second) {
            ans.second = max(ans.second, e.second);
        } else {
            printf("%04d-%04d\n", ans.first, ans.second);
            ans = e;
        }
    }
}
