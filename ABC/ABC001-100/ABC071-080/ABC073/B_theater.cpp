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
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        ans += r - l + 1;
    }
    cout << ans << endl;
}
