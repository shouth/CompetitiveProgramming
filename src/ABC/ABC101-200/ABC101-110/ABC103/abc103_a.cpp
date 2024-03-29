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
    vector<int> a(3);
    for (auto& e : a) cin >> e;
    sort(begin(a), end(a));
    int ans = 1e9;
    do {
        ans = min(abs(a[1] - a[0]) + abs(a[2] - a[1]), ans);
    } while (next_permutation(begin(a), end(a)));
    cout << ans << endl;
}
