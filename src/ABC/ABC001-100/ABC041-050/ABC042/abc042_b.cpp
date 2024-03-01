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
    int n, l;
    cin >> n >> l;
    vector<string> s(n);
    for (auto& e : s) cin >> e;
    sort(begin(s), end(s));
    cout << accumulate(begin(s), end(s), ""s) << endl;
}
