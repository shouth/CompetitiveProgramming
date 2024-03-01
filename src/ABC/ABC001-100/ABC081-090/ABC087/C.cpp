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
    vector<int> a1(n), a2(n);
    for (auto& e : a1) cin >> e;
    for (auto& e : a2) cin >> e;
    partial_sum(begin(a1), end(a1), begin(a1));
    partial_sum(rbegin(a2), rend(a2), rbegin(a2));

    int ans = 0;
    for (int i = 0; i < n; i++) ans = max(ans, a1[i] + a2[i]);

    cout << ans << endl;
}
