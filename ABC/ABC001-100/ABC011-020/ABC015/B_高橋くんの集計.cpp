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
    int n;
    cin >> n;
    int t = 0, d = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a != 0) t += a, d++;
    }

    cout << (t + d - 1) / d << endl;
}
