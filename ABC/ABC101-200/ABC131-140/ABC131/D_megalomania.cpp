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
    vector<pair<int64_t, int64_t>> ba(n);
    for (auto& e : ba) cin >> e.second >> e.first;

    sort(ba.begin(), ba.end());
    for (int64_t i=1; i<n; i++) ba[i].second += ba[i-1].second;

    cout << (all_of(ba.begin(), ba.end(), [&](auto e){ return e.first >= e.second; }) ? "Yes" : "No") << endl;
}
