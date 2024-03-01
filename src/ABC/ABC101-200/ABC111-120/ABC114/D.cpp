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

    vector<int> f(n+1);
    f[1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 2, d = i; j <= i; j++) {
            while (!(d % j)) {
                f[j]++;
                d /= j;
            }
        }
    }

    int ans = 0;

    for (int i = 2; i <= n - 2; i++) {
        for (int j = i + 1; j <= n - 1; j++) {
            for (int k = j + 1; k <= n; k++) {
                if (f[i] >= 2 && f[j] >= 4 && f[k] >= 4) ans++;
                if (f[i] >= 4 && f[j] >= 2 && f[k] >= 4) ans++;
                if (f[i] >= 4 && f[j] >= 4 && f[k] >= 2) ans++;
            }
        }
    }

    for (int i = 2; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (f[i] >= 2 && f[j] >= 24) ans++;
            if (f[i] >= 24 && f[j] >= 2) ans++;
            if (f[i] >= 4 && f[j] >= 14) ans++;
            if (f[i] >= 14 && f[j] >= 4) ans++;
        }
    }

    for (int i = 2; i <= n; i++) {
        if (f[i] >= 74) ans++;
    }

    cout << ans << endl;
}
