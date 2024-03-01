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
    sort(rbegin(a), rend(a));

    int alice = 0, bob = 0;
    for (int i = 0; i < n; i++) (i % 2 == 0 ? alice : bob) += a[i];
    cout << alice - bob << endl;
}
