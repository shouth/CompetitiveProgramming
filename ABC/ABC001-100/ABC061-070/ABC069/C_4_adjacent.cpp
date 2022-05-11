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
    int s = 0, t = 0, u = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        int tmp = 0;
        while (a % 2 == 0) a /= 2, tmp++;
        if (tmp == 0) s++;
        if (tmp == 1) t++;
        if (tmp >= 2) u++;
    }
    cout << (s - u <= 0 || ((s - u == 1) ^ (t > 0)) ? "Yes" : "No") << endl;
}
