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
    int k, x;
    cin >> k >> x;
    for (int i = max(x - k + 1, -1000000); i <= min(x + k - 1, 1000000); i++) {
        cout << i << endl;
    }
}
