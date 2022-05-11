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
    vector<int> s(n);
    for (auto& e : s) cin >> e;
    int ans = accumulate(begin(s), end(s), 0);
    if (ans % 10 == 0) {
        sort(begin(s), end(s));
        auto itr = find_if(begin(s), end(s), [](auto a) { return a % 10 != 0; });
        ans = itr != end(s) ? ans - *itr : 0;
    }
    cout << ans << endl;
}
