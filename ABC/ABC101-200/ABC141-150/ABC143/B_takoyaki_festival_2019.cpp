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
    vector<int> d(n);
    for (auto& e : d) cin >> e;

    int ans = 0;
    for (int i = 0; i + 1 < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans += d[i] * d[j];
        }
    }

    cout << ans << endl;
}
