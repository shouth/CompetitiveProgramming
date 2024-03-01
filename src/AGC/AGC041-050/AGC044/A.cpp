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

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 t;
    cin >> t;

    for (i64 i = 0; i < t; i++) {
        i64 n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;
        vector<p64> div { { 2, a }, { 3, b }, { 5, c } };

        map<i64, i64> costs { { 0, INF } };
        priority_queue<p64, vector<p64>, greater<>> pq;
        pq.emplace(0, n);

        while (!pq.empty()) {
            i64 cost, remain;
            tie(cost, remain) = pq.top(); pq.pop();

            if (costs.find(remain) != costs.end() && costs[remain] < cost) continue;

            if (costs[0] / d == cost / d + remain) {
                costs[0] = min(costs[0], cost + remain * d);
            } else if (costs[0] / d > cost / d + remain) {
                costs[0] = cost + remain * d;
            }

            for (auto& p : div) {
                i64 e, x;
                tie(e, x) = p;
                i64 tmp = remain % e;
                i64 up = (remain + e - tmp) / e, down = (remain - tmp) / e;
                i64 upcost = cost + (e - tmp) * d + x, downcost = cost + tmp * d + x;
                if (costs.find(up) == costs.end() || costs[up] > upcost) {
                    pq.emplace(costs[up] = upcost, up);
                }
                if (costs.find(down) == costs.end() || costs[down] > downcost) {
                    pq.emplace(costs[down] = downcost, down);
                }
            }
        }

        cout << costs[0] << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
