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
    int64_t a, b, k;
    cin >> a >> b >> k;
    if (a-k >= 0) {
        cout << a-k << " " << b << endl;
    } else if (a + b - k >= 0) {
        cout << 0 << " " << a + b - k << endl;
    } else {
        cout << 0 << " " << 0 << endl;
    }
}
