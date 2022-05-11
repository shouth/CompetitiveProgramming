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
    int64_t n;
    cin >> n;
    int64_t m = sqrt(n) + 1;

    int64_t ans;
    for (int64_t i = m; i > 0; i--) {
        if (n % i == 0) {
            ans = i - 1 + n / i - 1;
            break;
        }
    }

    cout << ans << endl;
}
