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
    string ans = "No";
    for (int i = 1; i <= 9; i++) {
        if (n % i == 0 && n / i < 10) ans = "Yes";
    }

    cout << ans << endl;
}
