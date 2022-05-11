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
    int n, s, t;
    cin >> n >> s >> t;
    int w;
    cin >> w;
    int ans = s <= w && w <= t;
    for (int i = 2; i <= n; i++) {
        int a;
        cin >> a;
        w += a, ans += s <= w && w <= t;
    }
    cout << ans << endl;
}
