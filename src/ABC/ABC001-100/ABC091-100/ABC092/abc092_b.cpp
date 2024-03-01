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
    int d, x;
    cin >> d >> x;
    vector<int> a(n);
    for (auto& e : a) cin >> e;

    int ans = x;
    for (auto& e : a) ans += 1 + (d - 1) / e;

    cout << ans << endl;
}
