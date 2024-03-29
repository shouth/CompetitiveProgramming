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
    int n, m;
    cin >> n >> m;
    vector<int> value(m);
    int total = 0;
    for (int i = 0; i < n; i++) {
        int l, r, s;
        cin >> l >> r >> s, l--;
        total += s;
        value[l] += s;
        if (r < m) value[r] -= s;
    }
    partial_sum(begin(value), end(value), begin(value));

    int ans = 0;
    for (auto& e : value) ans = max(ans, total - e);
    cout << ans << endl;
}
