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
    vector<int> c(1'000'002);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b, b++;
        c[a] += 1, c[b] -= 1;
    }
    partial_sum(begin(c), end(c), begin(c));

    int ans = 0;
    for (auto& e : c) ans = max(ans, e);
    cout << ans << endl;
}
