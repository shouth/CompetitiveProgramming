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
    auto itr = unique(begin(n), end(n));
    cout << (distance(begin(n), itr) == 1 ? "SAME" : "DIFFERENT") << endl;
}
