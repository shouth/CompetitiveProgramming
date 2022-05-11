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
    for (auto& e : p) cin >> e;
    sort(begin(p), end(p));

    cout << accumulate(begin(p), end(p) - 1, p.back() / 2) << endl;
}
