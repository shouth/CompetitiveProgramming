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
    vector<int> x(n);
    for (auto& e : x) cin >> e;
    int ans = INT_MAX;
    for (int i = 1; i <= 100; i++) {
        int can = 0;
        for (auto& e : x) {
            can += pow(e - i, 2);
        }
        ans = min(ans, can);
    }

    cout << ans << endl;
}
