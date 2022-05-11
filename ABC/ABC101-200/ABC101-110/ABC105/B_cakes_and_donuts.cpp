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
    string ans = "No";
    for (int c = 0; c <= n; c += 4) {
        for (int d = 0; c + d <= n; d += 7) {
            if (c + d == n) ans = "Yes";
        }
    }

    cout << ans << endl;
}
