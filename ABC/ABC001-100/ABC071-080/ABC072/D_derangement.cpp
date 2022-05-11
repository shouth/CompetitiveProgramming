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
    vector<int> p(n);
    for (auto& e : p) cin >> e, e--;
    int ans = 0;
    for (int i = 0; i + 1 < n; i++) {
        if (p[i] == i) {
            swap(p[i], p[i+1]);
            ans++;
        }
    }
    if (p.back() == n-1) ans++;
    cout << ans << endl;
}
