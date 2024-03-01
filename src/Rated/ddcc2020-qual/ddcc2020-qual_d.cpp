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
    int64_t m;
    cin >> m;
    int64_t dsum = 0, csum = 0;
    for (int64_t i = 0; i < m; i++) {
        int64_t d, c;
        cin >> d >> c;
        dsum += c * d;
        csum += c;
    }

    cout << csum-1 + (dsum-1)/9 << endl;
}
