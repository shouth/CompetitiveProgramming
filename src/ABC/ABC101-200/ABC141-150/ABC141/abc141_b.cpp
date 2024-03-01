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
    string ans = "Yes";
    for (int i = 0; i < s.size(); i += 2) {
        if (s[i] == 'L') {
            ans = "No";
            break;
        }
    }
    for (int i = 1; i < s.size(); i += 2) {
        if (s[i] == 'R') {
            ans = "No";
            break;
        }
    }
    cout << ans << endl;
}
