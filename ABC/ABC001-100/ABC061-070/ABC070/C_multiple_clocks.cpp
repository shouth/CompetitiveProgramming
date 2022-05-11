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
    vector<int64_t> t(n);
    for (auto& e : t) cin >> e;
    for (int64_t i = 0; i + 1 < n; i++) {
        t[i+1] = t[i] / __gcd(t[i], t[i+1]) * t[i+1];
    }
    cout << t.back() << endl;
}
