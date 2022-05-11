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
    string ans = "Yes";
    int t = 0, x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        int nt, nx, ny;
        cin >> nt >> nx >> ny;
        int d = abs(nt - t) - abs(nx - x) - abs(ny - y);
        if (d < 0 || d % 2 != 0) ans = "No";
        t = nt, x = nx, y = ny;
    }

    cout << ans << endl;
}
