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
    vector<int> l(n);
    for (auto& e : l) cin >> e;
    sort(begin(l), end(l));

    int ans = 0;
    for (int i = 0; i + 2 < n; i++) {
        for (int j = i + 1; j + 1 < n; j++) {
            auto itr = lower_bound(begin(l) + j + 1, end(l), l[i] + l[j]);
            ans += itr - (begin(l) + j + 1);
        }
    }

    cout << ans << endl;
}
