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
    vector<vector<int>> c(n+1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        c[a].push_back(b);
        c[b].push_back(a);
    }
    vector<int> v;
    sort(begin(c[1]), end(c[1]));
    sort(begin(c[n]), end(c[n]));
    set_intersection(begin(c[1]), end(c[1]), begin(c[n]), end(c[n]), back_inserter(v));
    cout << (!v.empty() ? "POSSIBLE" : "IMPOSSIBLE") << endl;
}
