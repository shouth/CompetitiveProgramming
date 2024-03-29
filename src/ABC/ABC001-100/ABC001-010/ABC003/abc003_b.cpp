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
    string ans = "You can win";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == t[i]) continue;
        if (s[i] == '@') swap(s[i], t[i]);
        if (t[i] == '@' && "atcoder"s.find(s[i]) != string::npos) continue;
        ans = "You will lose";
        break;
    }
    cout << ans << endl;
}
