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
    string s, t;
    cin >> s;
    t = s;

    while (true) {
        auto itr = adjacent_find(begin(t), end(t), [](auto a, auto b) { return a == '(' && b == ')'; });
        if (itr == end(t)) break;
        t.erase(itr, itr + 2);
    }

    int lb = count(begin(t), end(t), '('), rb = count(begin(t), end(t), ')');
    cout << string(rb, '(') << s << string(lb, ')') << endl;
}
