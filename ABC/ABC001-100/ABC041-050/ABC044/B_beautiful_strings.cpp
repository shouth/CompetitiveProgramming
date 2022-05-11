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
    string w;
    cin >> w;
    map<char, int> c;
    for (auto& e : w) c[e]++;
    string ans = "Yes";
    for (auto& e : c) if (e.second % 2 == 1) ans = "No";
    cout << ans << endl;
}
