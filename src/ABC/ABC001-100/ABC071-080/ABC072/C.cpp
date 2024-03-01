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
    vector<int> a(1e5);
    for (int i = 0; i < n; i++) {
        int aa;
        cin >> aa;
        a[aa]++;
    }
    int ans = 0;
    for (int i = 1; i < 1e5 - 1; i++) ans = max(ans, a[i-1] + a[i] + a[i+1]);
    cout << ans << endl;
}
