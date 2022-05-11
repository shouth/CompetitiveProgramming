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
    int n, m, x;
    cin >> n >> m >> x;

    vector<int> a(n+1);
    for (int i = 0; i < m; i++) {
        int ai;
        cin >> ai;
        a[ai] = 1;
    }
    for (int i = 0; i + 1 <= n; i++) a[i+1] += a[i];

    cout << min(a[x-1], m - a[x-1]) << endl;
}
