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
    int64_t d = log2(n);
    int64_t x = 1;
    while (true) {
        x = 2 * x + (d + 1) % 2;
        if (x > n) {
            cout << "Aoki" << endl;
            break;
        }
        x = 2 * x + d % 2;
        if (x > n) {
            cout << "Takahashi" << endl;
            break;
        }
    }
}
