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
    int a, b;
    cin >> a >> b;
    if ((a == 1 && b == 2) || (b == 1 && a == 2)) {
        cout << 3 << endl;
    } else if ((a == 2 && b == 3) || (b == 2 && a == 3)) {
        cout << 1 << endl;
    } else if ((a == 3 && b == 1) || (b == 3 && a == 1)) {
        cout << 2 << endl;
    }
}
