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

using i32 = int_fast32_t;
using i64 = int_fast64_t;

int main() {
    string s;
    cin >> s;
    cout << (s[2] == s[3] && s[4] == s[5] ? "Yes" : "No") << endl;
}
