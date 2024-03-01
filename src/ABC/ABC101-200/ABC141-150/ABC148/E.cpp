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

    int64_t ans = 0;
    if (n % 2 == 0) {
        for (int64_t i = 5; i <= n / 2; i *= 5) {
            ans += n / 2 / i;
        }
    }

    cout << ans << endl;
}
