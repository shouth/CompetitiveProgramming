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
    vector<int> l(n);
    for (auto& e : l) cin >> e;
    sort(begin(l), end(l), greater<>());
    cout << accumulate(begin(l), begin(l) + k, 0) << endl;
}
