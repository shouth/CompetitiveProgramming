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
    int n, x;
    cin >> n >> x;
    vector<int> l(n);
    for (auto& e : l) cin >> e;

    int d = 0;
    int ans = 1;
    for (auto e : l) {
        if (d + e > x) break;

        d += e;
        ans++;
    }

    cout << ans << endl;
}
