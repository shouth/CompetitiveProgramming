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
    s += '_';
    int n = s.size();
    for (int l = 0, r = 1; r < n; r++) {
        if (s[l] == s[r]) continue;
        cout << s[l] << r-l;
        l = r;
    }
    cout << endl;
}
