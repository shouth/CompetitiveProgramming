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

constexpr int lim = 1e5;

int main() {
    int q;
    cin >> q;
    vector<pair<int, int>> lr(q);
    for (auto& e : lr) cin >> e.first >> e.second;

    vector<int> p(lim + 10, 1), f(lim + 10);
    p[0] = p[1] = 0;
    for (int i = 2; i <= lim; i++) {
        if (!p[i]) continue;
        for (int j = i+i; j <= lim; j += i) p[j] = 0;
    }

    for (int i = 1; i <= lim; i += 2) f[i+1] = f[i] = f[i-1] + (p[i] && p[(i+1)/2]);
    for (auto& e : lr) cout << f[e.second] - f[e.first-1] << endl;
}
