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
    int n, x;
    cin >> n >> x;
    vector<int> m(n);
    for (auto& e : m) cin >> e;
    sort(begin(m), end(m));
    cout << n + (x - accumulate(begin(m), end(m), 0)) / m[0] << endl;
}
