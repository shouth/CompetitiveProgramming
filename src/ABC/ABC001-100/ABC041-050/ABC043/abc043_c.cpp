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

constexpr int INF = 1e9;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int maxa = -INF, mina = INF;
    for (auto& e : a) cin >> e, maxa = max(maxa, e), mina = min(mina, e);

    int ans = INF;
    for (int i = mina; i <= maxa; i++) {
        int can = 0;
        for (auto& e : a) can += pow(e - i, 2);
        ans = min(ans, can);
    }

    cout << ans << endl;
}
