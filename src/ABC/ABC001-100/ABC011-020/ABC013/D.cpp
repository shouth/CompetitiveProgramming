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
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> c(n);
    iota(begin(c), end(c), 0);
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a, a--;
        swap(c[a], c[a+1]);
    }

    vector<int> p(n);
    for (int i = 0; i < n; i++) p[c[i]] = i;

    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++) {
        if (ans[i] != -1) continue;
        vector<int> cycle { i };
        for (int j = p[i]; j != i; j = p[j]) cycle.push_back(j);
        for (int j = 0; j < cycle.size(); j++) ans[cycle[j]] = cycle[(j + d) % cycle.size()];
    }

    for (auto& e : ans) cout << e + 1 << endl;
}
