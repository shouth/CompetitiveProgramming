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
    int64_t a, b, x;
    cin >> a >> b >> x;

    int64_t bottom = 0, top = 1e9 + 1;
    while (abs(top-bottom) > 1) {
        int64_t n = (bottom + top) / 2;
        (a * n + b * ((int) log10(n) + 1) <= x ? bottom : top) = n;
    }
    cout << bottom << endl;
}
