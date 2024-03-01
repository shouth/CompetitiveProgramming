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

vector<string> split(string s, char c) {
    s += c;
    vector<string> res;
    for (auto i = begin(s), pi = i; i != end(s); i++) {
        if (*i != c) continue;
        res.push_back(string(pi, i));
        pi = i+1;
    }
    return res;
}

int main() {
    string s;
    cin >> s;
    auto ps = split(s, '+');
    int ans = 0;
    for (auto& e : ps) {
        auto ss = split(e, '*');
        if (find(begin(ss), end(ss), "0") == end(ss)) ans++;
    }
    cout << ans << endl;
}
