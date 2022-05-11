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
    string s;
    cin >> s;
    int64_t n = s.size();
    vector<int64_t> t(n);
    for (int64_t i = 0; i < n; i++) t[n-i-1] = s[i] - '0';
    int64_t ans = 0;
    for (int64_t b = 0; b < 1 << (n-1); b++) {
        ans += t[0];
        int64_t d = 1;
        for (int64_t i = 0; i < n-1; i++) {
            d = ((b >> i) & 1 ? d*10 : 1);
            ans += t[i+1] * d;
        }
    }
    cout << ans << endl;
}
