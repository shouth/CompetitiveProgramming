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
    int a, b, c;
    cin >> a >> b >> c;
    string ans = "!";
    if (a + b == c) ans = a == 0 || b == 0 ? "?" : "+";
    if (a - b == c) ans = a == 0 || b == 0 ? "?" : "-";
    cout << ans << endl;
}
