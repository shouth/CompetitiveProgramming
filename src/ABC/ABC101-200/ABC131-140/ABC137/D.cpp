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
    int64_t n, m;
    cin >> n >> m;

    vector<vector<int64_t>> r(m+1);
    for (int i = 0; i < n; i++) {
        int64_t a, b;
        cin >> a >> b;
        if (a <= m) r[a].push_back(b);
    }

    priority_queue<int64_t> pq;
    int64_t ans = 0;
    for (int i = 1; i <= m; i++) {
        for (auto e : r[i]) pq.push(e);
        if (!pq.empty()) {
            auto a = pq.top(); pq.pop();
            ans += a;
        }

    }
    cout << ans << endl;
}
