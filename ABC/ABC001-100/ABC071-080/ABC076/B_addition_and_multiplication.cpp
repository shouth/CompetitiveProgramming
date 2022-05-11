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
    int n, k;
    cin >> n >> k;
    int ans = 1;
    for (int i = 0; i < n; i++) ans = min(ans * 2, ans + k);
    cout << ans << endl;
}
