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
    sort(begin(s), end(s));
    auto itr = unique(begin(s), end(s));
    cout << (n == distance(begin(s), itr) ? "yes" : "no") << endl;
}
