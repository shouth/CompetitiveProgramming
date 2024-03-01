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
    string s, t;
    cin >> s >> t;

    map<char, char> m;
    string ans = "Yes";
    for (int i = 0, n = s.size(), sid = 1, tid = 1; i < n; i++) {
        if (m.find(s[i]) == m.end()) m[s[i]] = t[i];
        if (m[s[i]] != t[i]) ans = "No";
    }

    cout << ans << endl;
}
