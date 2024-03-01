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
    int n;
    cin >> n;
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        ans = min(ans, t);
    }
    cout << ans << endl;
}
