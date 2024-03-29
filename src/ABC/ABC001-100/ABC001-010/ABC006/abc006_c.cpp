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
    int n, m;
    cin >> n >> m;

    int x = -1, y = -1, z = -1;
    int l = m - 2 * n;
    for (int cy = 0; cy <= l; cy++) {
        if ((l - cy) % 2) continue;
        int cz = (l - cy) / 2;
        if (n - cy - cz < 0) continue;
        x = n - cy - cz, y = cy, z = cz;
        break;
    }

    cout << x << " " << y << " " << z << endl;
}
