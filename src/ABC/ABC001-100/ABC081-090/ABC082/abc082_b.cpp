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
    string s, t;
    cin >> s >> t;
    sort(begin(s), end(s));
    sort(begin(t), end(t), greater<>());
    cout << (s < t ? "Yes" : "No") << endl;

}
