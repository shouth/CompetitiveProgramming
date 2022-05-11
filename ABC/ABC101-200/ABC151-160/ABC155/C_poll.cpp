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
    map<string, int> c;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        c[s]++;
    }

    map<int, vector<string>, greater<>> d;
    for (auto& e : c) {
        d[e.second].push_back(e.first);
    }

    sort(begin(begin(d)->second), end(begin(d)->second));
    for (auto& e : begin(d)->second) {
        cout << e << endl;
    }
}
