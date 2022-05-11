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
    int n, k;
    cin >> n >> k;
    vector<int> neg, pos;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0) {
            k--;
        } else {
            (x < 0 ? neg : pos).push_back(abs(x));
        }
    }

    reverse(begin(neg), end(neg));
    neg.insert(begin(neg), 0);
    pos.insert(begin(pos), 0);

    int ans = 1e9;
    for (int i = min((int) neg.size() - 1, k); k - i <= min((int) pos.size() - 1, k); i--) {
        ans = min({ans, neg[i] * 2 + pos[k-i], neg[i] + pos[k-i] * 2});
    }

    cout << ans << endl;
}
