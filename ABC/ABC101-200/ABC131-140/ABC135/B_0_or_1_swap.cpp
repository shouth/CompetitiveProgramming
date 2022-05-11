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
    int d = 0;
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        if (p != i) d++;
    }

    cout << (d <= 2 ? "YES" : "NO") << endl;
}
