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

    string ans;

    if (n == 0) {
        ans = "0";
    } else {
        while (n != 0) {
            int r = n % -2;
            n /= -2;
            if (r < 0) n++;
            ans.push_back('0' + (r + 2) % 2);
        }
    }

    reverse(begin(ans), end(ans));
    cout << ans << endl;
}
