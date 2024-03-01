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
    string s;
    cin >> s;
    int n = s.size();
    s = '0' + s + '1';
    int ans = 1;
    for (int i = (n + 1) / 2, j = (n + 2) / 2; i >= 0 && j <= n + 1; i--, j++) {
        if (s[i] != s[(n + 1) / 2] || s[j] != s[(n + 1) / 2]) {
            ans = j - 1;
            break;
        }
    }

    cout << ans << endl;
}
