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
    string s;
    cin >> s;
    cout << (n % 2 == 0 && s.substr(0, n/2) == s.substr(n/2, n/2) ? "Yes" : "No") << endl;
}
