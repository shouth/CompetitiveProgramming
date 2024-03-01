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
    int n, k;
    cin >> n >> k;
    vector<char> d(k);
    for (auto& e : d) cin >> e;

    for (int i = n; i < 1e5; i++) {
        string ns = to_string(i);
        sort(begin(ns), end(ns));
        string tmp;
        set_intersection(begin(ns), end(ns), begin(d), end(d), back_inserter(tmp));
        if ((int) tmp.size() == 0) {
            cout << i << endl;
            return 0;
        }
    }
}
