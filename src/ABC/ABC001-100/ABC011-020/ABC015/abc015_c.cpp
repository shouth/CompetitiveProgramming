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

int n, k;
vector<vector<int>> s;

bool validate(int t = 0, int d = 0) {
    if (d == n) return t == 0;
    bool res = false;
    for (int i = 0; i < k; i++) res |= validate(t ^ s[d][i], d + 1);
    return res;
}

int main() {
    cin >> n >> k;
    s.resize(n, vector<int>(k));
    for (auto& e : s) for (auto& f : e) cin >> f;
    cout << (validate() ? "Found" : "Nothing") << endl;
}
