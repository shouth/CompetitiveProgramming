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
    int t;
    cin >> t;
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& e : a) cin >> e;
    int m;
    cin >> m;
    vector<int> b(m);
    for (auto& e : b) cin >> e;

    int ia = 0, ib = 0;
    while (ia != n && ib != m) {
        if (a[ia] > b[ib]) break;
        if (b[ib] - a[ia] <= t) ib++;
        ia++;
    }

    cout << (ib == m ? "yes" : "no") << endl;
}
