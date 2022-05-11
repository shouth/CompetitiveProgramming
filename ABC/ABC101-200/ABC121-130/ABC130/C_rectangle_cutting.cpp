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
    double w, h, x, y;
    cin >> w >> h >> x >> y;

    cout << w*h/2 << " " << (w/2 == x && h/2 == y) << endl;
}
