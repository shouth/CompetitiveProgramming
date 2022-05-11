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
    map<int, int> a;
    for (int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
        a[ai]++;
    }

    int ans = 0;
    for (auto& e : a) ans += (e.second >= e.first ? e.second - e.first : e.second);

    cout << ans << endl;
}
