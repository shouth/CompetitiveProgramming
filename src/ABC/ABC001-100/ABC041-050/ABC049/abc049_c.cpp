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
    reverse(begin(s), end(s));
    vector<string> w { "dream", "dreamer", "erase", "eraser" };
    for (auto& e : w) reverse(begin(e), end(e));

    int pos = 0, ppos = -1;
    while (ppos != pos) {
        ppos = pos;
        for (auto& e : w) if (s.substr(pos, e.size()) == e) pos += e.size();
    }

    cout << (pos == (int) s.size() ? "YES" : "NO") << endl;
}
