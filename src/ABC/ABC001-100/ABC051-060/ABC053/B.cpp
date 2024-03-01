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
    auto a = find(begin(s), end(s), 'A');
    auto z = find(rbegin(s), rend(s), 'Z');
    cout << (int) s.size() - distance(begin(s), a) - distance(rbegin(s), z) << endl;
}
