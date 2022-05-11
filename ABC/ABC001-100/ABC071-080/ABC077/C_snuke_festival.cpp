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
    int64_t n;
    cin >> n;
    vector<pair<int64_t, int64_t>> p;
    for (auto& e : { 3, 2, 1 }) {
        for (int i = 0; i < n; i++) {
            int pp;
            cin >> pp;
            p.emplace_back(pp, e);
        }
    }
    sort(begin(p), end(p));
    int64_t a = 0, b = 0, c = 0;
    for (auto& e : p) {
        switch (e.second) {
        case 3:
            a++;
            break;
        case 2:
            b += a;
            break;
        case 1:
            c += b;
            break;
        }
    }
    cout << c << endl;
}
