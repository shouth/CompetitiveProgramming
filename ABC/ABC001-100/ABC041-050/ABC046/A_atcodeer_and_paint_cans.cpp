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
    vector<int> abc(3);
    for (auto& e : abc) cin >> e;
    sort(begin(abc), end(abc));
    auto itr = unique(begin(abc), end(abc));
    cout << distance(begin(abc), itr) << endl;
}
