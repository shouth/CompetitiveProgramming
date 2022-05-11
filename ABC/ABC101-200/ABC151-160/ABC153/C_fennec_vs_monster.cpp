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
    int64_t n, k;
    cin >> n >> k;
    vector<int64_t> h(n);
    for (auto& e : h) cin >> e;
    sort(begin(h), end(h));
    cout << (k < n ? accumulate(begin(h), begin(h) + n - k, 0l) : 0) << endl;
}
