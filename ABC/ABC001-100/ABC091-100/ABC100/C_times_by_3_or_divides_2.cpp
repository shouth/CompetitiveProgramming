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
    vector<int> a(n);
    for (auto& e : a) cin >> e;

    int ans = 0;
    for (auto& e : a) {
        while (e % 2 == 0) ans++, e /= 2;
    }

    cout << ans << endl;
}
