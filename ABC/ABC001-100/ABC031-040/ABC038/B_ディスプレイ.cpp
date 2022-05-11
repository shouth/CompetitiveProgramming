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
    int h1, w1, h2, w2;
    cin >> h1 >> w1 >> h2 >> w2;
    cout << (h1 == h2 || h1 == w2 || w1 == w2 || w1 == h2 ? "YES" : "NO") << endl;
}
