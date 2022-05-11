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
    vector<int> p(n);
    for (auto& e : p) {
        cin >> e;
    }

    int ans = 0;
    for (int i = 1; i < n-1; i++) {
        if ((p[i-1] < p[i] && p[i] < p[i+1]) || (p[i-1] > p[i] && p[i] > p[i+1])) {
            ans++;
        }
    }

    cout << ans << endl;
}
