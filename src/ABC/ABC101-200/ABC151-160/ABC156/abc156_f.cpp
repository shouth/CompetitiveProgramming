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
    int64_t k, q;
    cin >> k >> q;
    vector<int64_t> d(k);
    for (auto& e : d) cin >> e;
    partial_sum(begin(d), end(d), begin(d));

    for (int64_t i = 0; i < q; i++) {
        int64_t n, x, m;
        cin >> n >> x >> m;
        int64_t ans = 0;
        int64_t p = x;
        for (int j = 0; j < n; j++) {
            int64_t q = (p + d[j % k]) % m;

        }
    }
}
