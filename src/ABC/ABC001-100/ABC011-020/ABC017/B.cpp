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
    string x;
    cin >> x;
    int n = x.size();
    string ans = "YES";
    for (int i = 0; i < n; i++) {
        if (x[i] == 'o' || x[i] == 'k' || x[i] == 'u') continue;
        if (x[i++] == 'c' && x[i] == 'h') continue;
        ans = "NO";
        break;
    }

    cout << ans << endl;
}
