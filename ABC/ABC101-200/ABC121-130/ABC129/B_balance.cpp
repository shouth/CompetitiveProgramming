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

    vector<int> w(n), acc(n+1);
    for (auto& e : w) cin >> e;
    for (int i = 0; i < n; i++) acc[i+1] = acc[i] + w[i];

    int ans = 1e9;
    for (int i = 1; i < n; i++) {
        ans = min(ans, abs(acc[n] - acc[i] - acc[i]));
    }

    cout << ans << endl;
}
