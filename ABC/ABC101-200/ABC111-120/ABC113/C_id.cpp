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

struct city {
    int p;
    int y;
    int n;
    string id;
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<city> c(m);
    for (int i = 0; i < m; i++) {
        cin >> c[i].p >> c[i].y;
        c[i].n = i;
    }

    sort(begin(c), end(c), [](auto a, auto b) { return a.p == b.p ? a.y < b.y : a.p < b.p ; });
    for (int i = 0, s = -1, t = 1; i < m; i++, t++) {
        if (c[i].p != s) s = c[i].p, t = 1;
        stringstream ss;
        ss << setfill('0') << setw(6) << c[i].p;
        ss << setfill('0') << setw(6) << t;
        c[i].id = ss.str();
    }

    sort(begin(c), end(c), [](auto a, auto b) { return a.n < b.n; });
    for (auto e : c) cout << e.id << endl;
}
