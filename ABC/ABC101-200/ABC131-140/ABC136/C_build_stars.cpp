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
    int64_t n;
    cin >> n;
    vector<int64_t> h(n);
    for (auto& e : h) cin >> e;
    string ans = "Yes";
    for (int i = n - 1; i - 1 >= 0; i--) {
        if (h[i-1] - h[i] == 1) h[i-1]--;
        if (h[i-1] - h[i] > 1) ans = "No";
    }
    cout << ans << endl;
}
