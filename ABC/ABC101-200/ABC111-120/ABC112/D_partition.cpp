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

    vector<int> d;
    for (int i = 1; i * i <= m; i++) {
        if (m % i != 0) continue;
        d.push_back(i);
        if (i * i != m) d.push_back(m / i);
    }

    sort(begin(d), end(d));
    cout << m / *lower_bound(begin(d), end(d), n) << endl;
}
