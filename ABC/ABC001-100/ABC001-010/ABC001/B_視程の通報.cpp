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
    int m;
    cin >> m;

    int vv = 0;
    if (100 <= m && m <= 5000) {
        vv = m / 100;
    } else if (6000 <= m && m <= 30000) {
        vv = m / 1000 + 50;
    } else if (35000 <= m && m <= 70000) {
        vv = (m / 1000 - 30) / 5 + 80;
    } else if (70000 <= m) {
        vv = 89;
    }

    cout << setw(2) << setfill('0') << vv << endl;
}
