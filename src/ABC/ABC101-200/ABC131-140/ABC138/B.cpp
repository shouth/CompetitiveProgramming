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
    double d = 0;
    for (int i = 0; i < n; i++) {
        double a;
        cin >> a;
        d += 1 / a;
    }

    cout << setprecision(10) << 1 / d << endl;
}
