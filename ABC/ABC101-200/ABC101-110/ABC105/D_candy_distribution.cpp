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
    int n, m;
    cin >> n >> m;
    vector<int64_t> a(n);
    for (auto& e : a) cin >> e;
    vector<int64_t> acc(n+1);
    acc[0] = 0;
    for (int64_t i = 0; i + 1 < n + 1; i++) acc[i+1] += acc[i] + a[i];

    map<int64_t, int64_t> rs;
    int64_t ans = 0;
    for (auto& e : acc) {
        int64_t i = e % m;
        ans += rs[i]++;
    }

    cout << ans << endl;
}
