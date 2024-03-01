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
    priority_queue<int64_t> pq;
    for (size_t i = 0; i < n; i++) {
        int64_t a;
        cin >> a;
        pq.push(a);
    }
    for (size_t i = 0; i < m; i++) {
        int64_t a = pq.top(); pq.pop();
        a /= 2;
        pq.push(a);
    }
    int64_t ans = 0;
    while (!pq.empty()) {
        int64_t a = pq.top(); pq.pop();
        ans += a;
    }

    cout << ans << endl;
}
