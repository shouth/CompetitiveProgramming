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
    string n;
    cin >> n;
    cout << ((n[0] == n[1] && n[1] == n[2]) || (n[1] == n[2] && n[2] == n[3]) ? "Yes" : "No") << endl;
}
