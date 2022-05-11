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
    int a, b;
    cin >> a >> b;
    int ans = 0;
    for (int i = a; i <= b; i++) {
        string s = to_string(i);
        if (s[0] == s[4] && s[1] == s[3]) ans++;
    }

    cout << ans << endl;
}
