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
    int h, n;
    cin >> h >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        h -= t;
    }

    cout << (h <= 0 ? "Yes" : "No") << endl;
}
