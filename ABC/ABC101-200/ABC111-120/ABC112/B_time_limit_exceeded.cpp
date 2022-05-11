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
    int n, t;
    cin >> n >> t;

    int ans = 1e5;
    bool exist = false;
    for (int i = 0; i < n; i++) {
        int c, s;
        cin >> c >> s;
        if (s <= t) {
            ans = min(ans, c);
            exist = true;
        }
    }

    if (exist) {
        cout << ans << endl;
    } else {
        cout << "TLE" << endl;
    }
}
