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
    int x, y;
    cin >> x >> y;
    cout << (max(4-x, 0)+max(4-y,0)) * 100000 + (x == 1 && y == 1 ? 400000 : 0) << endl;
}
