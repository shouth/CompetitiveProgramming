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
    map<char, vector<int>> s;
    for (int i = 0; i < n; i++) {
        string ss;
        cin >> ss;
        map<char, int> c;
        for (auto& e : ss) c[e]++;
        for (char i = 'a'; i <= 'z'; i++) s[i].push_back(c[i]);
    }

    string ans = "";
    for (auto& e : s) {
        int m = *min_element(begin(e.second), end(e.second));
        ans += string(m, e.first);
    }
    cout << ans << endl;
}
