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
    vector<int> c(n-1), s(n-1), f(n-1);
    for (int i = 0; i < n - 1; i++) cin >> c[i] >> s[i] >> f[i];

    for (int i = 0; i < n; i++) {
        int tmp = 0;
        for (int j = i; j + 1 < n; j++) {
            tmp = tmp <= s[j] ? s[j] + c[j] : (tmp + f[j] - 1) / f[j] * f[j] + c[j];
        }
        cout << tmp << endl;;
    }
}
