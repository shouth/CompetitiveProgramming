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
    string s;
    cin >> s;
    int64_t n = s.size();
    vector<int64_t> v(n+1);
    for (int64_t i = n-1; i >= 0; i--) {
        v[i] = v[i+1];
        if (s[i] == '+') v[i]++;
        if (s[i] == '-') v[i]--;
    }

    vector<int64_t> use;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'M') use.push_back(v[i]);
    }

    sort(begin(use), end(use));
    int64_t l = accumulate(begin(use), begin(use) + use.size() / 2, 0);
    int64_t g = accumulate(begin(use) + use.size() / 2, end(use), 0);
    cout << g - l << endl;
}
