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
    int n, y;
    cin >> n >> y;

    int ansx = -1, ansy = -1, ansz = -1;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n - i; j++) {
            if (10000 * i + 5000 * j + (n - i - j) * 1000 == y) ansx = i, ansy = j, ansz = n - i - j;
        }
    }

    cout << ansx << " " << ansy << " " << ansz << endl;
}
