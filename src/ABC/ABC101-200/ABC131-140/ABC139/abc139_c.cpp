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
    vector<int> h(n);
    for (auto& e : h) cin >> e;
    h.push_back(1e9 + 7);
    int ans = 0;
    for (int i = 0, l = 0; i < n; i++) {
        if (h[i+1] <= h[i]) continue;
        ans = max(ans, i - l);
        l = i + 1;
    }
    cout << ans << endl;
}
