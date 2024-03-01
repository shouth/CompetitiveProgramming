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
    int64_t q;
    cin >> q;
    vector<pair<int64_t, int64_t>> ab(q);
    for (auto& e : ab) cin >> e.first >> e.second;

    for (auto& e : ab) {
        double d = 2.0 * sqrt(e.first * e.second);
        if ((int64_t) d == d) {
            d -= 2;
            if (e.first != e.second) d--;
        } else {
            d = (int64_t) d - 2;
        }

        cout << (int64_t) d << endl;
    }
}
