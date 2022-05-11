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
    bool a = s[0] == 'A';
    bool c = count(begin(s) + 2, end(s) - 1, 'C') == 1;
    s[0] = 'a', *find(begin(s) + 2, end(s) - 1, 'C') = 'c';
    bool small = all_of(begin(s), end(s), ::islower);

    cout << (a && c && small ? "AC" : "WA") << endl;
}
