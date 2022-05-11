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

    int ans = 1e9;
    for (int i = 1; i <= sqrt(n); i++) {
        int j = n / i;
        ans = min(ans, abs(i - j) + n - i * j);
    }

    cout << ans << endl;
}
