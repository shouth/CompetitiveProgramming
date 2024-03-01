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
    vector<int> h(n);
    for (auto& e : h) cin >> e;

    h.push_back(0);

    int ans = 0;
    for (int i = 1, lim = *max_element(h.begin(), h.end()); i <= lim; i++) {
        for (int j = 0; j < n; j++) {
            if (h[j] >= i && h[j+1] < i) ans++;
        }
    }

    cout << ans << endl;
}
