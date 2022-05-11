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
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int d = abs(x1 - x2 + y1 - y2);
    cout << y1 - y2 + x2 << " " << -x1 + x2 + y2 << " " << -y2 + y1 + x1 << " " << x2 - x1 + y1 << endl;
}
