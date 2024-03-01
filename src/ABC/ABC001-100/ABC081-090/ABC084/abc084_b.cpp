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
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    bool h = s[a] == '-';
    s.erase(begin(s) + a);
    bool n = all_of(begin(s), end(s), ::isdigit);
    cout << (h && n ? "Yes" : "No") << endl;
}
