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
    string ans = "Bad";
    switch (n / 10) {
    case 6:
    case 7:
    case 8:
        ans = "Good";
        break;
    case 9:
        ans = "Great";
        break;
    case 10:
        ans = "Perfect";
        break;
    }

    cout << ans << endl;
}
