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
    int n = s.size();
    int l = -1, r = -1;
    for (int i = 0; i+2 <= n; i++) {
        if (s[i] == s[i+1]) {
            l = i+1, r = i+2;
            break;
        } else if (i+3 <= n && (s[i+1] == s[i+2] || s[i+2] == s[i])) {
            l = i+1, r = i+3;
            break;
        }
    }

    cout << l << " " << r << endl;
}
