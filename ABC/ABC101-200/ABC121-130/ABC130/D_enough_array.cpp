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
    int64_t n, k;
    cin >> n >> k;
    vector<int64_t> a(n);
    for(auto& e : a) cin >> e;
    vector<int64_t> s(n+1);
    s[0] = 0, s[1] = a[0];
    for(int i=2; i<=n; i++) {
        s[i] = s[i-1] + a[i-1];
    }

    int64_t ans = 0, preright = 1;
    for (int left = 0; left < n; left++) {
        for (int right = preright; right <= n; right++) {
            if (s[right] - s[left] >= k) {
                ans += n - right + 1;
                preright = right;
                break;
            }
        }
    }
    cout << ans << endl;
}
