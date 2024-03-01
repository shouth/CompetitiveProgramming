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
    int r, g, b;
    cin >> r >> g >> b;
    cout << ((r * 100 + g * 10 + b) % 4 == 0 ? "YES" : "NO") << endl;
}
