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
    vector<string> s(3);
    for (auto& e : s) cin >> e;
    vector<int> is(3);
    int t = 0;
    while (is[t] != (int) s[t].size()) t = s[t][is[t]++] - 'a';
    cout << (char) ('A' + t) << endl;
}
