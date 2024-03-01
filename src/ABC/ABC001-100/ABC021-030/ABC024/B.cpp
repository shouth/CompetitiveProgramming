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
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (auto& e : a) cin >> e;
    a.push_back(1e9);

    int ans = 0;
    for (int i = 0; i < n; i++) ans += min(t, a[i+1] - a[i]);
    cout << ans << endl;
}
