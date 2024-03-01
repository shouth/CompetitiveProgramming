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
    vector<int> a(n + 2, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> gl(n+2), gr(n+2);
    gl[0] = 0, gr[n+1] = 0;
    for (int i = 0; i + 1 <= n + 1; i++) gl[i+1] = max(gl[i], a[i+1]);
    for (int i = n + 1; i - 1 >= 0; i--) gr[i-1] = max(gr[i], a[i-1]);

    for (int i = 1; i <= n; i++) {
        cout << max(gl[i-1], gr[i+1]) << endl;
    }
}
