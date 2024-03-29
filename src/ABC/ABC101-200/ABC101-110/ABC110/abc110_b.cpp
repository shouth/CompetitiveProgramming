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
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<int> xs(n), ys(m);
    for (auto& e : xs) cin >> e;
    for (auto& e : ys) cin >> e;

    xs.push_back(x);
    ys.push_back(y);

    if (*max_element(begin(xs), end(xs)) < *min_element(begin(ys), end(ys))) {
        cout << "No War" << endl;
    } else {
        cout << "War" << endl;
    }
}
