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

constexpr int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        int aa;
        cin >> aa, a[aa]++;
    }

    int ans = 1;
    for (int i = 0; i < n; i++) {
        if ((i == 0 && n%2 == 1 && a[i] != 1)
            || (i != 0 && i%2 != n%2 && a[i] != 2)
            || (i%2 == n%2 && a[i] != 0)) {
            ans = 0;
        }
    }

    if (ans) {
        for (int i = 0; i < n / 2; i++) ans = ans * 2 % MOD;
    }
    cout << ans << endl;
}
