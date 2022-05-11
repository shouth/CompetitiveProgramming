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
    n = 2025 - n;
    for (int x = 1; x <= 9; x++) {
        if (n % x == 0 && n / x <= 9) cout << x << " x " << n / x << endl;
    }
}
