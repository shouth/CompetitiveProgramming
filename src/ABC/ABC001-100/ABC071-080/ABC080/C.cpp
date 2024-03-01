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
    vector<bitset<10>> f(n);
    for (auto& e : f) {
        for (int i = 0; i < 10; i++) {
            int ff;
            cin >> ff;
            e |= ff << i;
        }
    }

    vector<vector<int>> p(n, vector<int>(11));
    for (auto& e : p) for (auto& f : e) cin >> f;

    int ans = -1e9;
    for (int i = 1; i < 1 << 10; i++) {
        int can = 0;
        for (int j = 0; j < n; j++) can += p[j][(f[j] & bitset<10>(i)).count()];
        ans = max(ans, can);
    }

    cout << ans << endl;
}
