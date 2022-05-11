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
    int m = 1e9, ans = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (m >= a) ans++;
        m = min(m, a);
    }
    cout << ans << endl;
}
