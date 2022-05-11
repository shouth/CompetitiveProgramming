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
    int64_t r, d, x;
    cin >> r >> d >> x;

    for (int i=0; i<10; i++) {
        x = r*x - d;
        cout << x << endl;
    }
}
