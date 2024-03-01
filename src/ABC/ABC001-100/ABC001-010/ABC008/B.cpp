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
    map<string, int> c;
    string ans = "";
    int x = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (x < ++c[s]) {
            x = c[s];
            ans = s;
        }
    }

    cout << ans << endl;
}
