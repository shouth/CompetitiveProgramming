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
    vector<char> s(n);
    for (auto& e : s) cin >> e;
    sort(begin(s), end(s));
    auto itr = unique(begin(s), end(s));
    cout << ((itr - begin(s)) == 3 ? "Three" : "Four") << endl;
}
